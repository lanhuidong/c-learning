#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "util.h"
#include "bytecode.h"

void print_access_flags(uint16_t access_flags);

void parse(FILE *fp)
{
    struct ClassFile *cfp = (struct ClassFile *)malloc(sizeof(struct ClassFile));
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

    parse_constant_pool(fp, cfp);

    uint16_t access_flags;
    fread(&access_flags, sizeof(uint16_t), 1, fp);
    access_flags = isBigEndian() ? access_flags : BigLittleSwap16(access_flags);
    cfp->access_flags = access_flags;

    uint16_t this_class;
    fread(&this_class, sizeof(uint16_t), 1, fp);
    this_class = isBigEndian() ? this_class : BigLittleSwap16(this_class);
    cfp->this_class = this_class;

    uint16_t super_class;
    fread(&super_class, sizeof(uint16_t), 1, fp);
    super_class = isBigEndian() ? super_class : BigLittleSwap16(super_class);
    cfp->super_class = super_class;

    uint16_t interface_count;
    fread(&interface_count, sizeof(uint16_t), 1, fp);
    interface_count = isBigEndian() ? interface_count : BigLittleSwap16(interface_count);
    cfp->interface_count = interface_count;
    
    uint16_t *interfaces = (uint16_t *)malloc(sizeof(uint16_t) * interface_count);
    cfp->interfaces = interfaces;
    fread(interfaces, sizeof(uint16_t), interface_count, fp);
    for(int i = 0; i < interface_count; i++){
        interfaces[i] = isBigEndian() ? interfaces[i] : BigLittleSwap16(interfaces[i]);
    }

    printf("魔数:%X\n", cfp->magic);
    printf("字节码文件版本号: %u.%u, JDK1.%u\n", cfp->major_version, cfp->minor_version, cfp->major_version-44);

    print_constants(cfp);
    print_access_flags(access_flags);
    printf("this=%u, super=%u\n", this_class, super_class);
    printf("interface num is %u\n", interface_count);
    for(int i = 0; i < interface_count; i++){
        printf("interface %d is #%u\n", i, interfaces[i]); 
    }
    
    free(cfp);
}

void print_access_flags(uint16_t access_flags){
    printf("Access Flags:\n");
    if((access_flags & 0x0001) != 0){
        printf("\tpublic\n");
    }
    if((access_flags & 0x0010) != 0){
        printf("\tfinal\n");
    }
    if((access_flags & 0x0020) != 0){
        printf("\tsuper\n");
    }
    if((access_flags & 0x0200) != 0){
        printf("\tinterface\n");
    }
    if((access_flags & 0x0400) != 0){
        printf("\tabstract\n");
    }
    if((access_flags & 0x1000) != 0){
        printf("\tsynthetic\n");
    }
    if((access_flags & 0x2000) != 0){
        printf("\tannotation\n");
    }
    if((access_flags & 0x4000) != 0){
        printf("\tenum\n");
    }
}
