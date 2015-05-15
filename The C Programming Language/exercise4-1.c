#include <stdio.h>
#define MAXLINE 1000

int readline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    while (readline(line, MAXLINE) > 0)
    {
        if (strrindex(line, pattern) >= 0)
	{
	    printf("%s", line);
	    found++;
	}
    }
    return found;
}

int readline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int strrindex(char s[], char t[])
{
    int i, j, k, slength, tlength;
    slength = 0;
    tlength = 0;
    for(i = 0; s[i] !='\0'; i++)
    {
        slength++;
    }
    for(i = 0; t[i] !='\0'; i++)
    {
        tlength++;
    }
    
    for (i = slength - 1; s[i] != '\0'; i--)
    {
        for (j = i, k = tlength - 1; j >= 0 && k >= 0 && s[j] == t[k]; j--, k--)
	{    
            if (k == 0)
	    {
	        break;
	    }
	}
	if (k == 0)
	{
            printf("the rightmost index is %d\n", i - tlength + 1);
	    return i - tlength + 1;
	}
    }
    printf("not found\n");
    return -1;
}
