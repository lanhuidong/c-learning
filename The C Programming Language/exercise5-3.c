#include <stdio.h>

void mystrcat(char *s, char *t);

int main(int argc, char *argv[])
{
    char s[] = "hello,";
    char t[] = " world!";
    mystrcat(s, t);
    printf("%s\n", s);
    return 0;
}
void mystrcat(char *s, char *t)
{
    while (*s != '\0')
    {
        s++;
    }
    while ((*s++ = *t++) != '\0')
    {
    }

}
