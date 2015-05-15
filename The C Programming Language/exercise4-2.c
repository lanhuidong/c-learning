#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

double atof(char s[])
{
    double val, power;
    int i, j, sign, scientific;

    for (i = 0; isspace(s[i]); i++)
    {
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = val * 10.0 + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = val * 10.0 + (s[i] - '0');
	power *= 10.0;
    }
    val = sign * val / power;
    
    /*handle scientific notation*/
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (scientific = 0; isdigit(s[i]); i++)
    {
        scientific = scientific * 10 + (s[i] - '0');
    }
    for (i = 0; i < scientific; i++)
    {
        if (sign == 1)
	{
	    val *= 10.0;
	} 
	else 
	{
	    val /= 10.0;
	}
    }
    return val;
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

int main()
{
    double sum;
    char line[MAXLINE];
    while (readline(line, MAXLINE) > 0)
    {
        printf("\t%g\n", sum += atof(line));
    }
    return 0;
}
