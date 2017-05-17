#include<stdio.h>

int main(void)
{
    int i= 0;
    struct{
        int array[4];
    }a={{1,2,3,4}},b;

    b = a;
    for(i=0;i<4;i++){
        printf("%d, %d\n",a.array[i], b.array[i]);
    }
    return 0;
}
