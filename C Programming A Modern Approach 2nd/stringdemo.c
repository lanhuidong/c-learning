#include<stdio.h>

int main(void)
{
    /*如果两个字符串之间只有空白字符，编译器会将两个字符串连接到一起*/
    printf("Hello "
    "world!\n");
    
    printf("Hello \0 world!");
    printf("\n");

    return 0;
}
