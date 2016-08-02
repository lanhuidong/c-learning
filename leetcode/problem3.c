#include<stdio.h>

int lengthOfLongestSubstring(char* s);

int main(void){
    char* s = "abcdabcbb";
    int length = lengthOfLongestSubstring(s);
    printf("%d\n", length);
    return 0;
}

int lengthOfLongestSubstring(char* s){
    int a[256] = {0};
    int index = 0;
    int round = 1;
    int maxLength = 0;
    int length = 0;
    while(*s != '\0'){
        length = 1;
	a[*s] = round;
        char* s1 = s; 
        s1++;
        while(*s1 != '\0'){
            if(a[*s1]==round){
                break;
            } else {
                a[*s1]=round;
            }
            length++;
	    s1++;
        }
	maxLength = maxLength > length ? maxLength : length;
	s++;
        round++;
    }
    return maxLength;
}
