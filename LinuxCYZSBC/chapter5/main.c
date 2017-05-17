#include<stdio.h>
/*加-Wall选项gcc会给出警告信息，当x=0时返回不确定值*/
int abs(int x)
{
    if(x < 0)
    {
        return -x;
    } else if(x>0) 
    {
        return x;
    }
}

int main(void)
{
    int x = 0;
    x = abs(x);
    printf("%d\n", x);
    return 0;
}
