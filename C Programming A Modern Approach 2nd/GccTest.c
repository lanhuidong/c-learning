#include<stdio.h>
int main(void)
{
    int i = 0;
    //当使用gcc -Wall或-Wparentheses选项时，把“=”当作“==”使用会发出警告
    //可以使用if((i=0))来压制警告
    if(i = 0)
    {
        printf("i=%d\n", i);
    }
    return 0;
}
