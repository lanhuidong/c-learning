#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "util.h"
#include "bytecode.h"

void parse_utf8_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_integer_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_float_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_long_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_double_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_class_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_string_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_fieldref_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_methodref_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_interfacemethodref_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_nameandtype_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);

void parse_constant_pool(FILE *fp,struct ClassFile *cfp)
{
    uint16_t constant_pool_count;
    fread(&constant_pool_count, sizeof(uint16_t), 1, fp);
    constant_pool_count = isBigEndian() ? constant_pool_count : BigLittleSwap16(constant_pool_count);
    cfp->constant_pool_count = constant_pool_count;

    struct Cp_info *info =(struct Cp_info *)malloc(sizeof(struct Cp_info));
    cfp->constant_pool = info;
    cfp->constant_pool =(struct Cp_info *)malloc(constant_pool_count * sizeof(struct Cp_info));

    uint8_t tag;
    for(uint16_t i = 1; i < constant_pool_count; i++) {
        fread(&tag, sizeof(uint8_t), 1, fp);
	switch(tag){
	    case 1:
                parse_utf8_info(i, tag, fp, cfp);
	        break;
	    case 3:
                parse_integer_info(i, tag, fp, cfp);
	        break;
	    case 4:
                parse_float_info(i, tag, fp, cfp);
	        break;
	    case 5:
                parse_long_info(i, tag, fp, cfp);
		i++;
	        break;
	    case 6:
                parse_double_info(i, tag, fp, cfp);
		i++;
	        break;
	    case 7:
                parse_class_info(i, tag, fp, cfp);
	        break;
	    case 8:
                parse_string_info(i, tag, fp, cfp);
	        break;
	    case 9:
                parse_fieldref_info(i, tag, fp, cfp);
	        break;
	    case 10:
	        parse_methodref_info(i, tag, fp, cfp);
	        break;
	    case 11:
	        parse_interfacemethodref_info(i, tag, fp, cfp);
	        break;
	    case 12:
	        parse_nameandtype_info(i, tag, fp, cfp);
	        break;
	    case 15:
	        break;
	    case 16:
	        break;
	    case 18:
	        break;
            default:printf("unkonw tag %u\n", tag);
        }
    }
}

void parse_utf8_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint16_t length;
    fread(&length, sizeof(uint16_t), 1, fp);
    length = isBigEndian() ? length : BigLittleSwap16(length);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.utf8_info.length = length;
    cfp->constant_pool[index].info.utf8_info.bytes = (uint8_t *)malloc(length * sizeof(uint8_t));
    fread(cfp->constant_pool[index].info.utf8_info.bytes, sizeof(uint8_t), length, fp);
}

void parse_integer_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint32_t bytes;
    fread(&bytes, sizeof(uint32_t), 1, fp);
    bytes = isBigEndian() ? bytes : BigLittleSwap32(bytes);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.integer_info.bytes = bytes;
}

void parse_float_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint32_t bytes;
    fread(&bytes, sizeof(uint32_t), 1, fp);
    bytes = isBigEndian() ? bytes : BigLittleSwap32(bytes);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.float_info.bytes = bytes;
}

void parse_long_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint32_t high_bytes, low_bytes;
    fread(&high_bytes, sizeof(uint32_t), 1, fp);
    high_bytes = isBigEndian() ? high_bytes : BigLittleSwap32(high_bytes);
    fread(&low_bytes, sizeof(uint32_t), 1, fp);
    low_bytes = isBigEndian() ? low_bytes : BigLittleSwap32(low_bytes);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.long_info.high_bytes = high_bytes;
    cfp->constant_pool[index].info.long_info.low_bytes = low_bytes;
}

void parse_double_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint32_t high_bytes, low_bytes;
    fread(&high_bytes, sizeof(uint32_t), 1, fp);
    high_bytes = isBigEndian() ? high_bytes : BigLittleSwap32(high_bytes);
    fread(&low_bytes, sizeof(uint32_t), 1, fp);
    low_bytes = isBigEndian() ? low_bytes : BigLittleSwap32(low_bytes);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.double_info.high_bytes = high_bytes;
    cfp->constant_pool[index].info.double_info.low_bytes = low_bytes;
}

void parse_class_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint16_t name_index;
    fread(&name_index, sizeof(uint16_t), 1, fp);
    name_index = isBigEndian() ? name_index : BigLittleSwap16(name_index);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.class_info.name_index = name_index;
}

void parse_string_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint16_t string_index;
    fread(&string_index, sizeof(uint16_t), 1, fp);
    string_index = isBigEndian() ? string_index : BigLittleSwap16(string_index);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.string_info.string_index = string_index;
}

void parse_fieldref_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint16_t class_index, name_and_type_index;
    fread(&class_index, sizeof(uint16_t), 1, fp);
    class_index = isBigEndian() ? class_index : BigLittleSwap16(class_index);
    fread(&name_and_type_index, sizeof(uint16_t), 1, fp);
    name_and_type_index = isBigEndian() ? name_and_type_index : BigLittleSwap16(name_and_type_index);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.fieldref_info.class_index = class_index;
    cfp->constant_pool[index].info.fieldref_info.name_and_type_index = name_and_type_index;
}

void parse_methodref_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint16_t class_index, name_and_type_index;
    fread(&class_index, sizeof(uint16_t), 1, fp);
    class_index = isBigEndian() ? class_index : BigLittleSwap16(class_index);
    fread(&name_and_type_index, sizeof(uint16_t), 1, fp);
    name_and_type_index = isBigEndian() ? name_and_type_index : BigLittleSwap16(name_and_type_index);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.methodref_info.class_index = class_index;
    cfp->constant_pool[index].info.methodref_info.name_and_type_index = name_and_type_index;
}

void parse_interfacemethodref_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint16_t class_index, name_and_type_index;
    fread(&class_index, sizeof(uint16_t), 1, fp);
    class_index = isBigEndian() ? class_index : BigLittleSwap16(class_index);
    fread(&name_and_type_index, sizeof(uint16_t), 1, fp);
    name_and_type_index = isBigEndian() ? name_and_type_index : BigLittleSwap16(name_and_type_index);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.interfaceMethodref_info.class_index = class_index;
    cfp->constant_pool[index].info.interfaceMethodref_info.name_and_type_index = name_and_type_index;
}

void parse_nameandtype_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint16_t name_index, descriptor_index;
    fread(&name_index, sizeof(uint16_t), 1, fp);
    name_index = isBigEndian() ? name_index : BigLittleSwap16(name_index);
    fread(&descriptor_index, sizeof(uint16_t), 1, fp);
    descriptor_index = isBigEndian() ? descriptor_index : BigLittleSwap16(descriptor_index);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.nameAndType_info.name_index = name_index;
    cfp->constant_pool[index].info.nameAndType_info.descriptor_index = descriptor_index;
}

