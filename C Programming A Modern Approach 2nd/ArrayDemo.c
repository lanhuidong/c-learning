#include<stdio.h>

int main(void)
{
    int a[3][3] = {0};
    int *p;
    for(p = a[1]; p < a[1] + 3; p++)
    {
        *p = 1;
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
	{
	    printf("%d ", a[i][j]);
	}
	printf("\n");
    } 
    int (*q)[3];
    for(q = &a[0]; q < &a[0] + 3; q++)
    {
        (*q)[1] = 2;
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
	{
	    printf("%d ", a[i][j]);
	}
	printf("\n");
    }
    return 0;
}
