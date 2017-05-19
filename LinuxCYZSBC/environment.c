#include<stdio.h>
#include<stdlib.h>

/*
 * 打印环境变量 
 */
int main(void)
{
    putenv("c=c99");
    setenv("JAVA_HOME", ".", 0);  /*第三个参数为0则不覆盖已存在的环境变量*/
    setenv("gcc", "4.8", 0);
    extern char **environ; /*因为environ没有包含在任何头文件中，因此需要用extern声明*/
    int i;
    for(i = 0; environ[i] != NULL; i++){
        printf("%s\n", environ[i]);
    }
    printf("\n");
    printf("PATH=%s\n", getenv("PATH"));
    setenv("PATH", ".", 1);
    printf("PATH=%s\n", getenv("PATH"));
    unsetenv("JAVA_HOME");
    printf("JAVA_HOME=%s\n", getenv("JAVA_HOME"));
    return 0;
}
