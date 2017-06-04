#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "util.h"
#include "bytecode.h"

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

    printf("魔数:%X\n", cfp->magic);
    printf("字节码文件版本号: %u.%u, JDK1.%u\n", cfp->major_version, cfp->minor_version, cfp->major_version-44);

    print_constants(cfp);
    
    free(cfp);
}

