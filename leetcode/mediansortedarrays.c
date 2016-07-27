#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main(void){
    int a[] = {1,2,3};
    int b[] = {4};
    double result = findMedianSortedArrays(a,3,b,1);
    printf("result=%f\n", result);
    return 0;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *high1, *high2;
    int count1 = 0, count2 = 0;
    high1 = nums1 + nums1Size - 1;
    high2 = nums2 + nums2Size - 1;
    while((nums1Size - count1 > 0)&&(nums2Size - count2 > 0)){
        if(*nums1 > *nums2){
            count2++;
            if(nums2 != high2){
                nums2++;
            }
        } else {
            count1++;
            if(nums1 != high1){
                nums1++;
            }
        }
        if((nums1Size - count1 > 0)&&(nums2Size - count2 > 0)){
            if(*high1 > *high2){
                count1++;
                if(high1 != nums1){
                    high1--;
                }
            } else {
                count2++;
                if(high2 != nums2){
                   high2--;
                }
            }
        } else if(nums1Size - count1 > 0){
            count1++;
            if(high1 != nums1){
                high1--;
            }
        } else if(nums2Size - count2 > 0){
            count2++;
            if(high2 != nums2){
                high2--;
            }
        }
    }
    if(nums1Size - count1 == 1){
        return *nums1;
    } else if(nums1Size - count1 > 0 &&(nums1Size - count1)%2 == 0){
        return (*(nums1 + (nums1Size - count1) /2 - 1)+*(nums1+(nums1Size - count1)/2)) / 2.0;
    } else if(nums1Size - count1 > 0){
        return *(nums1 + (nums1Size - count1) / 2);
    }

    if(nums2Size - count2 == 1){
        return *nums2;
    } else if(nums2Size - count2 > 0 &&(nums2Size - count2)%2 == 0){
        return (*(nums2 + (nums2Size-count2) /2-1)+*(nums2+(nums2Size-count2)/2)) / 2.0;
    } else if(nums2Size - count2 > 0){
        return *(nums2 + (nums2Size - count2) / 2);
    }
    return (*nums1 + *nums2) / 2.0;
}

