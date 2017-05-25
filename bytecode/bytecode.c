#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define BigLittleSwap32(A) ((((uint32_t)(A) & 0xff000000) >> 24) | \
                           (((uint32_t)(A) & 0x00ff0000) >> 8) | \
                           (((uint32_t)(A) & 0x0000ff00) << 8) | \
                           (((uint32_t)(A) & 0x000000ff) << 24))

int isBigEndian();

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
    uint32_t magic;
    fread(&magic, sizeof(uint32_t), 1, fp);
    //magic = isBigEndian() ? magic : BigLittleSwap32(magic);
    if(!isBigEndian()){
        magic = BigLittleSwap32(magic);
    }
    printf("magic: %X\n", magic);
    fclose(fp);
    return 0;
}

/**
 * 返回0表示小端，返回非0值表示大端
 */
int isBigEndian(){
    int i = 1;
    char c = *(char *)&i;
    return (int)c != i;
}
