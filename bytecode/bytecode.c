#include<stdio.h>
#include<stdint.h>
#include "bytecode.h"

#define BigLittleSwap16(A) ((((uint16_t)(A) & 0xff00) >> 8) | \
                           (((uint16_t)(A) & 0x00ff) << 8))
#define BigLittleSwap32(A) ((((uint32_t)(A) & 0xff000000) >> 24) | \
                           (((uint32_t)(A) & 0x00ff0000) >> 8) | \
                           (((uint32_t)(A) & 0x0000ff00) << 8) | \
                           (((uint32_t)(A) & 0x000000ff) << 24))

int isBigEndian();

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
}

/**
 * 返回0表示小端，返回非0值表示大端
 */
int isBigEndian(){
    int i = 1;
    char c = *(char *)&i;
    return (int)c != i;
}
