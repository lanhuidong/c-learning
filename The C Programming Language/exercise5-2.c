#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getfloat(double *pn);

int main(int arg, char *argv[])
{
    double d;
    if(getfloat(&d))
    {
        printf("%f\n", d);
    }
    return 0;
}

int getfloat(double *pn)
{
    int c, sign, hassign;
    double power;
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
    if (c == '.')
    {
        c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn = sign * *pn / power;
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
