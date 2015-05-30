#include "sort.h" 

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
