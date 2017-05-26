#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "bytecode.h"

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("请输入文件名。\n");
	exit(0);
    }
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        perror("open bytecode file error.");
	exit(1);
    }
    struct ClassFile *cfp = (struct ClassFile *)malloc(sizeof(struct ClassFile));
    parse(fp, cfp);
    printf("magic:%X\n", cfp->magic);
    printf("version: %u.%u, JDK1.%u\n", cfp->major_version, cfp->minor_version, cfp->major_version-44);
    uint16_t constant_pool_count = cfp->constant_pool_count;
    printf("constant_pool_count:%u\n", constant_pool_count);
    for(uint16_t i = 0; i < constant_pool_count; i++){
        printf("#%d=%u,%u,%u\n", i+1, cfp->constant_pool[i].tag,cfp->constant_pool[i].info.methodref_info.class_index,cfp->constant_pool[i].info.methodref_info.name_and_type_index);
        break;
    }
    free(cfp);
    fclose(fp);
    return 0;
}
