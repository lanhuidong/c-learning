#include <stdio.h>

int main()
{
    printf("char size: %dbytes\n", sizeof(char));
    printf("unsigned char size: %dbytes\n", sizeof(unsigned char));
    printf("short int size: %dbytes\n", sizeof(short int));
    printf("int size: %dbytes\n", sizeof(int));
    printf("long int size: %dbytes\n", sizeof(long int));
    printf("long long size: %dbytes\n", sizeof(long long));
    printf("float size: %dbytes\n", sizeof(float));
    printf("double size: %dbytes\n", sizeof(double));
    printf("long double size: %dbytes\n", sizeof(long double));
    return 0;
}
