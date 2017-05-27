#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "bytecode.h"
#include "constant_pool_out.h"

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
    printf("魔数:%X\n", cfp->magic);
    printf("字节码文件版本号: %u.%u, JDK1.%u\n", cfp->major_version, cfp->minor_version, cfp->major_version-44);
    print_constants(cfp);
    free(cfp->constant_pool);
    free(cfp);
    fclose(fp);
    return 0;
}
