#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "bytecode.h"

void print_utf8(uint16_t length, uint8_t *bytes);
double toFloat(uint32_t bytes);

void print_constants(struct ClassFile *cfp){
    uint16_t constant_pool_count = cfp->constant_pool_count;
    printf("总共有%u项常量\n", constant_pool_count);
    for(uint16_t i = 0; i < constant_pool_count - 1; i++){
        uint8_t tag = cfp->constant_pool[i].tag;
	printf("#%-5d = ", i + 1);
	switch(tag){
            case 1:
	        printf("UTF-8      \t\t");
		print_utf8(cfp->constant_pool[i].info.utf8_info.length, cfp->constant_pool[i].info.utf8_info.bytes);
	        break;
	    case 3:
	        printf("Integer    \t\t%d\n", cfp->constant_pool[i].info.integer_info.bytes);
	        break;
	    case 4:
	        printf("Float      \t\t%.5gf\n", toFloat(cfp->constant_pool[i].info.float_info.bytes));
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

double toFloat(uint32_t bits){
    int s = ((bits >> 31) == 0) ? 1 : -1; 
    int e = ((bits >> 23) & 0xff);
    int m = (e == 0) ? (bits & 0x7fffff) << 1 : (bits & 0x7fffff) | 0x800000;
    return s * m * pow( 2, e - 150 );
}
