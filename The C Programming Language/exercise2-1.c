#include <stdio.h>
#include <limits.h>

main()
{
    printf("char %d\n", CHAR_BIT);
    printf("min char %d\n", CHAR_MIN);
    printf("max char %d\n", CHAR_MAX);
    printf("min short %d\n", SHRT_MAX);
    printf("max short  %d\n", SHRT_MAX);
    printf("min int %d\n", INT_MIN);
    printf("max int %d\n", INT_MAX);
    printf("min long %ld\n", LONG_MIN);
    printf("max long %ld\n", LONG_MAX);
    printf("max unsigned char %u\n", UCHAR_MAX);
    printf("max unsigned short %u\n", USHRT_MAX);
    printf("max unsigned int %u\n", UINT_MAX);
    printf("max unsigned long %lu\n", ULONG_MAX);
}
