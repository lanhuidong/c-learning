/*
 * 当有符号数转无符号数时，2^n+原来的值
 */
#include<stdio.h>
int main(void)
{
    unsigned int ui = 3;
    int i1 = -10;
    int i2 = 10;
    unsigned int ui2;
    ui2 = i1;
    printf("%u\n", i1 + ui);
    printf("%u\n", -9);
    printf("%u\n", ui2);
    return 0;
}
