#include <stdio.h>
void test();

void test(){
    test:
        printf("goto test");
}

int main()
{
    
    int x = 1;
    if(x){
        goto test;
    }
    test:
        printf("test label in main");
    return 0;
}
