#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void trim(char line[]);
void reverse(char s[]);

int main(int argc, char *argv[])
{
    int len;
    char line[MAXLINE];
    while ((len = mygetline(line, MAXLINE)) > 0)
    {
        trim(line);
	reverse(line);
        printf("%s\n", line);
    }
    return 0;
}

int mygetline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if(c == '\n')
    {
        s[i] = c;
	i++;
    }
    s[i] = '\0';
    return i;
}

void trim(char s[])
{
    int i, j, len;
    i = 0;
    len = 0;
    while (s[i++] != '\0')
    {
        len++;
    }
    j = len - 1;
    i = 0;
    while (j > 0)
    {
       if (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
       {
          i++; 
       }
       else
       {
           break;
       }
       j--;
    }
    s[len - i] = '\0';
}

void reverse(char s[])
{
    char c;
    int i, len;
    i = 0;
    len = 0;
    while (s[i++] != '\0')
    {
        len++;
    }
    for (i = 0; i < len / 2; i++)
    {
        c = s[i];
	s[i] = s[len - 1 - i];
	s[len - 1 - i] = c;
    }
}
