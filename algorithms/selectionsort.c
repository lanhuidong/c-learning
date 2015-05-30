#include <stdio.h>

void selectionsort(int a[], int length);

int main(int argc, char *argv)
{
    int i, length;
    int a[] = {12, 34, 14, 6, 67, 89, 23, 77, 6, 19, 86, 87};

    length = sizeof a / sizeof a[0];

    printf("original array:\n");
    for (i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");

    selectionsort(a, length);

    printf("after selection sort:\n");
    for (i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

/*
 * 选择排序：
 * 首先，找到数组中最小的元素和数组中第一个元素交换
 * 接着找到数组中第二小的元素和数组中第二个元素交换
 * 依此类推，直到整个数组从小到大排好序
 */
void selectionsort(int a[], int length)
{
    int i, j, min, tmp;

    for (i = 0; i < length; i++)
    {
        min = i;
        for (j = i + 1; j < length; j++)
	    if (a[min] > a[j])
	        min = j;
	tmp = a[i];
	a[i] = a[min];
	a[min] = tmp;
    }
}
