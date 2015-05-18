#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getint(int *pn);

int main(int arg, char *argv[])
{
    int i;
    if(getint(&i))
    {
        printf("%d\n", i);
    }
    return 0;
}

int getint(int *pn)
{
    int c, sign, hassign;
    while (isspace(c = getch()))
    {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
	return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (hassign = (c == '+' || c == '-'))
    {
        c = getch();
    }
    if (!isdigit(c))
    {
	if (hassign)
	{
	    ungetch((sign = -1) ? '-' : '+');
            ungetch(c);
	}
	return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
