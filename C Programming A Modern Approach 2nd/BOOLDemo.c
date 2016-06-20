#include<stdio.h>
#include<stdbool.h>
int main(void)
{
    //赋值给_Bool类型的非零值都会转换成1
    _Bool b = 5;
    printf("b=%d\n", b);
    //bool, true, false需要引入stdbool.h
    bool flag = true;
    printf("flag=%d\n", flag);
    return 0;
}
