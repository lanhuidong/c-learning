#include <stdio.h>
#define MAXLINES 5000
#define MAXLEN 1000
#define BUFSIZE 10000

int mygetline(char *s, int lim);
int readlines(char *lineptr[], char *line, int maxlines);

int main(int argc, char *argv[])
{
    char *lineptr[MAXLINES];
    char buf[BUFSIZE];
    int nlines, i;
    nlines = 0;
    if ((nlines = readlines(lineptr, buf, MAXLINES)) >= 0)
    {
        for (i = 0; i < nlines; i++)
	{
	    printf("%d:%s\n", i, lineptr[i]);
	}
    }
    return 0;
}

int mygetline(char *s, int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        *(s + i) = c;
        i++;
    }
    if (c == '\n')
    {
        *(s + i) = c;
        i++;
    }
    *(s+i) = '\0';
    return i;
}

int readlines(char *lineptr[], char *line,  int maxlines)
{
    int len, nlines;

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
    { 
        if (nlines >= maxlines)
	    return -1;
	else
	{
	    line[len - 1] = '\0';
	    lineptr[nlines++] = line;
	    line = line + len;
	}
    }
    return nlines;
}
