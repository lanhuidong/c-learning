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
    free(cfp);
    fclose(fp);
    return 0;
}
