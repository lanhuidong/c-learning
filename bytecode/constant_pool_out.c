#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "bytecode.h"

void print_utf8(uint16_t length, uint8_t *bytes);
void toFloat(uint32_t bytes);
void toLong(uint32_t high_bytes, uint32_t low_bytes);
void toDouble(uint32_t high_bytes, uint32_t low_bytes);

void print_constants(struct ClassFile *cfp){
    uint16_t constant_pool_count = cfp->constant_pool_count;
    printf("总共有%u项常量\n", constant_pool_count);
    for(uint16_t i = 1; i < constant_pool_count; i++){
        uint8_t tag = cfp->constant_pool[i].tag;
	printf("#%-5d = ", i);
	switch(tag){
            case 1:
	        printf("UTF-8      \t\t");
		print_utf8(cfp->constant_pool[i].info.utf8_info.length, cfp->constant_pool[i].info.utf8_info.bytes);
	        break;
	    case 3:
	        printf("Integer    \t\t%d\n", cfp->constant_pool[i].info.integer_info.bytes);
	        break;
	    case 4:
	        printf("Float      \t\t");
	        toFloat(cfp->constant_pool[i].info.float_info.bytes);
	        break;
	    case 5:
	        printf("Long       \t\t");
                toLong(cfp->constant_pool[i].info.long_info.high_bytes, cfp->constant_pool[i].info.long_info.low_bytes);
	        i++;
	        break;
	    case 6:
	        printf("Double     \t\t");
                toDouble(cfp->constant_pool[i].info.double_info.high_bytes, cfp->constant_pool[i].info.double_info.low_bytes);
	        i++;
	        break;
            case 7:
	        printf("Class      \t\t#%u\n", cfp->constant_pool[i].info.class_info.name_index);
                break;
	    case 8:
	        printf("String     \t\t#%u\n", cfp->constant_pool[i].info.string_info.string_index);
	        break;
	    case 9:
                printf("Fieldref   \t\t#%u.#%u\n", cfp->constant_pool[i].info.fieldref_info.class_index,cfp->constant_pool[i].info.fieldref_info.name_and_type_index);
	        break;
	    case 10:
                printf("Methodref  \t\t#%u.#%u\n", cfp->constant_pool[i].info.methodref_info.class_index,cfp->constant_pool[i].info.methodref_info.name_and_type_index);
	        break;
	    case 12:
                printf("NameAndType\t\t#%u.#%u\n", cfp->constant_pool[i].info.nameAndType_info.name_index,cfp->constant_pool[i].info.nameAndType_info.descriptor_index);
	        break;
	    default:
	    printf("unkonw tag:%u\n", tag);
	}
    }
}

void print_utf8(uint16_t length, uint8_t *bytes){
    for(uint16_t i = 0; i < length; i++){
        putchar(*bytes);
	*bytes++;
    }
    putchar('\n');
}

void toFloat(uint32_t bits){
    if(bits == 0x7f800000) {
        printf("POSITIVE_INFINITY\n");
    } else if(bits == 0xff800000) {
        printf("NEGATIVE_INFINITY\n");
    } else if(bits >= 0x7f800001 && bits <= 0x7fffffff || bits >= 0xff800001 && bits <= 0xffffffff) {
        printf("NaN\n");
    } else {
        int s = ((bits >> 31) == 0) ? 1 : -1; 
        int e = ((bits >> 23) & 0xff);
        int m = (e == 0) ? (bits & 0x7fffff) << 1 : (bits & 0x7fffff) | 0x800000;
        double result = s * m * pow( 2, e - 150 );
        printf("%.5gf\n", result);
    }
}

void toLong(uint32_t high_bytes, uint32_t low_bytes){
    uint64_t result = ((uint64_t)high_bytes << 32) + low_bytes; 
    printf("%ld\n", result);
}

void toDouble(uint32_t high_bytes, uint32_t low_bytes){
    uint64_t bits = ((uint64_t)high_bytes << 32) + low_bytes; 
    if(bits == 0x7ff0000000000000) {
        printf("POSITIVE_INFINITY\n");
    } else if(bits == 0xfff0000000000000) {
        printf("NEGATIVE_INFINITY\n");
    } else if(bits >= 0x7ff0000000000001 && bits <= 0x7fffffffffffffff || bits >= 0xfff0000000000001 && bits <= 0xffffffffffffffff) {
        printf("NaN\n");
    } else {
        int s = ((bits >> 63) == 0) ? 1 : -1;
        int e = (int)((bits >> 52) & 0x7ffL);
	long m = (e == 0) ? (bits & 0xfffffffffffffL) << 1 : (bits & 0xfffffffffffffL) | 0x10000000000000L;
        double result = s * m * pow( 2, e - 1075 );
        printf("%.17gd\n", result);
    }
}
