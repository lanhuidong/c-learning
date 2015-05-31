#include <stdio.h>
#include "sort.h"

int main(int argc, char *argv)
{
    int i, length;
    int a[] = {12, 34, 14, 6, 67, 89, 23, 77, 6, 19, 86, 87};

    length = sizeof a / sizeof a[0];

    printf("original array:\n");
    for (i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");

    insertionsort(a, length);

    printf("after sort:\n");
    for (i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
