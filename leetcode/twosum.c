#include<stdio.h>

int* twosum(int* nums, int numsSize, int target);

int main(void)
{
    int a[] = {2, 7, 11, 15};
    int* idx = twosum(a, 4, 26);
    printf("%d\n", *idx);
    idx++;
    printf("%d\n", *idx);
    return 0;
}

int* twosum(int* nums, int numsSize, int target)
{
    static int a[2];
    for(int i = 0; i < numsSize - 1; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
	{
	    if(nums[i] + nums[j] == target)
	    {
	        a[0] = i;
		a[1] = j;
	        return a;
	    }
	}
    }
    return a;
}
