#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(int argc, char *argv[])
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index;
    index = binsearch(9, array, (sizeof array)/ (sizeof array[0]));
    printf("find %d in array %d\n", 9, index);
    index = binsearch(-2, array, (sizeof array)/ (sizeof array[0]));
    printf("find %d in array %d\n", -2, index);
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n -1;
    while (low < high)
    {
        mid = (low + high) / 2;
	if (x <= v[mid])
	{
	    high = mid;
	}
	else
	{
	    low = mid + 1;
	}
    }
    return (x == v[low]) ? v[low] : -1;
}
