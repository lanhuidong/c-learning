#include <stdio.h>
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

/*
 * 插入排序：
 * 在一个有序的小序列中插入一个元素，比较从小序列末尾开始，
 * 如果最后一个元素大于要插入的元素，则交换位置，继续和前面元素比较，直到找到小于等于它的元素
 */
void insertionsort(int a[], int length)
{
    int i, j, tmp;
    for (i  = 0; i < length; i++)
        for (j = i; j > 0 && a[j] < a[j - 1]; j--)
	{
	    tmp = a[j];
	    a[j] = a[j - 1];
	    a[j - 1] = tmp;
	}
}

/*
 * 希尔排序：
 * 插入排序的扩展版
 */
void shellsort(int a[], int length)
{
    int h, i, j, tmp;
    h = 1;
    while (h < length / 3)
        h = 3 * h +1;
    while (h >= 1)
    {
        for (i = h; i < length; i++)
	{
	    for (j = i; j >= h && a[j] < a[j - h]; j -= h)
	    {
	        tmp = a[j];
		a[j] = a[j - h];
		a[j - h] = tmp;
	    }
	}
	h = h / 3;
    }
}

/*
 * 归并排序
 */
void merge(int a[], int aux[], int lo, int mid, int hi)
{
    int i = lo, j = mid + 1, k;
    for (k = lo; k <= hi; k++)
        aux[k] = a[k];
    for (k = lo; k <= hi; k++)
    {
        if (i > mid)
	    a[k] = aux[j++];
	else if (j > hi)
	    a[k] = aux[i++];
	else if (aux[j] < aux[i])
	    a[k] = aux[j++];
	else
	    a[k] = aux[i++];
    }
}

void mergesort(int a[], int length)
{
    int sz, lo, min;
    int aux[length];
    for (sz = 1; sz < length; sz = sz + sz)
        for (lo = 0; lo < length - sz; lo += sz + sz)
	{
	    int min = length - 1;
	    if (min > lo + sz + sz - 1)
	        min = lo + sz + sz - 1;
	    merge(a, aux, lo, lo + sz - 1, min);
	}
}

void recursive_sort(int a[], int aux[], int lo, int hi)
{
    int mid;
    if (hi <= lo)
        return;
    mid = lo + (hi - lo) / 2;
    recursive_sort(a, aux, lo, mid);
    recursive_sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

void mergesort_r(int a[], int length)
{
    int aux[length];
    recursive_sort(a, aux, 0, length - 1);
}

/*快速排序*/
int partition(int a[], int lo, int hi)
{
    int i, j, k, tmp;
    i = lo;
    j = hi + 1;
    k = a[lo];
    while (11111111111)
    {
        while (a[++i] < k)
	    if (i == hi)
	        break;
        while (k < a[--j])
	    if (j == lo)
	        break;
	if (i >=j )
	    break;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
    }
    tmp = a[lo];
    a[lo] = a[j];
    a[j] = tmp;
    return j;
}

void qsort(int a[], int lo, int hi)
{
    int j;
    if (hi <= lo)
        return;
    j = partition(a, lo, hi);
    qsort(a, lo, j - 1);
    qsort(a, j + 1, hi);
}

void quicksort(int a[], int length)
{
    qsort(a, 0, length - 1);
}
