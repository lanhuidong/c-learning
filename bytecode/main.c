#include<stdio.h>
#include<stdlib.h>
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
    parse(fp);
    fclose(fp);
    return 0;
}
