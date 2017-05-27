#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "bytecode.h"

#define BigLittleSwap16(A) ((((uint16_t)(A) & 0xff00) >> 8) | \
                           (((uint16_t)(A) & 0x00ff) << 8))
#define BigLittleSwap32(A) ((((uint32_t)(A) & 0xff000000) >> 24) | \
                           (((uint32_t)(A) & 0x00ff0000) >> 8) | \
                           (((uint32_t)(A) & 0x0000ff00) << 8) | \
                           (((uint32_t)(A) & 0x000000ff) << 24))

int isBigEndian();
void parse_methodref_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);
void parse_fieldref_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp);

void parse(FILE *fp,struct ClassFile *cfp)
{
    uint32_t magic;
    fread(&magic, sizeof(uint32_t), 1, fp);
    //magic = isBigEndian() ? magic : BigLittleSwap32(magic);
    if(!isBigEndian()){
        magic = BigLittleSwap32(magic);
    }
    cfp->magic = magic;
    uint16_t version[2];
    fread(version, sizeof(uint16_t), 2, fp);
    version[0] = isBigEndian() ? version[0] : BigLittleSwap16(version[0]);
    version[1] = isBigEndian() ? version[1] : BigLittleSwap16(version[1]);
    cfp->minor_version = version[0];
    cfp->major_version = version[1];
    uint16_t constant_pool_count;
    fread(&constant_pool_count, sizeof(uint16_t), 1, fp);
    constant_pool_count = isBigEndian() ? constant_pool_count : BigLittleSwap16(constant_pool_count);
    cfp->constant_pool_count = constant_pool_count;

    struct Cp_info *info =(struct Cp_info *)malloc(sizeof(struct Cp_info));
    cfp->constant_pool = info;
    cfp->constant_pool =(struct Cp_info *)malloc(constant_pool_count * sizeof(struct Cp_info));

    uint8_t tag;
    for(uint16_t i = 0; i < constant_pool_count; i++) {
        fread(&tag, sizeof(uint8_t), 1, fp);
	switch(tag){
	    case 1:
	    break;
	    case 3:
	    break;
	    case 4:
	    break;
	    case 5:
	    break;
	    case 6:
	    break;
	    case 7:
	    break;
	    case 8:
	    break;
	    case 9:
            parse_fieldref_info(i, tag, fp, cfp);
	    break;
	    case 10:
	    parse_methodref_info(i, tag, fp, cfp);
	    break;
	    case 11:
	    break;
	    case 12:
	    break;
	    case 15:
	    break;
	    case 16:
	    break;
	    case 18:
	    break;
            default:printf("unkonw tag %u\n", tag);
        }
        if(i==1){
            break;
        }
    }
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

void parse_fieldref_info(uint16_t index, uint8_t tag, FILE *fp, struct ClassFile *cfp){
    uint16_t class_index, name_and_type_index;
    fread(&class_index, sizeof(uint16_t), 1, fp);
    class_index = isBigEndian() ? class_index : BigLittleSwap16(class_index);
    fread(&name_and_type_index, sizeof(uint16_t), 1, fp);
    name_and_type_index = isBigEndian() ? name_and_type_index : BigLittleSwap16(name_and_type_index);
    cfp->constant_pool[index].tag = tag;
    cfp->constant_pool[index].info.fieldref_info.class_index = class_index;
    cfp->constant_pool[index].info.fieldref_info.name_and_type_index = name_and_type_index;
    printf("index=%d\n", index);
}

/**
 * 返回0表示小端，返回非0值表示大端
 */
int isBigEndian(){
    int i = 1;
    char c = *(char *)&i;
    return (int)c != i;
}
