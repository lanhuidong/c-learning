#include <stdio.h>

void mystrncpy(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);

int main(int argc, char *argv[])
{
    char s1[] = "hello";
    char t1[] = "world";
    char s2[100] = "hello, ";
    char t2[] = "world!";
    char s3[] = "java";
    char t3[] = "javascript";
    
    int n = 3;
    int result;

    mystrncpy(s1, t1, n);
    printf("results: %s\n", s1);

    mystrncat(s2, t2, n);
    printf("result: %s\n", s2);

    result = mystrncmp(s3, t3, n);
    printf("result: %d\n", result);

    result = mystrncmp(s3, t3, 5);
    printf("result: %d\n", result);


    result = mystrncmp(t3, s3, 5);
    printf("result: %d\n", result);
}

void mystrncpy(char *s, char *t, int n)
{
    int i;
    i = 0;
    while (i < n && *t != '\0')
    {
        *s++ = *t++;
        i++;
    }
}

void mystrncat(char *s, char *t, int n)
{
    int i;
    i = 0;
    while (*s != '\0')
    {
        *s++;
    }
    while (i < n && *t != '\0')
    {
        *s++ = *t++;
	i++;
    }
}

int mystrncmp(char *s, char *t, int n)
{
    int i;
    for (i = 0; i < n && *s == *t; s++, t++)
    {
        i++;
    }
    return *s - *t;
}
