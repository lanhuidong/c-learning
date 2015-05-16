#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c, lcase;
    char *arg;
    arg = *++argv;
    if (strcmp(arg, "lower") == 0)
    {
        lcase = 0;
    }
    else if (strcmp(arg, "upper") == 0)
    {
        lcase = 1;
    }
    else
    {
        printf("no commond line argument!\n");
	return 0;
    }
    while ((c = getchar()) != EOF)
    {
        if(lcase == 0)
	{
	    putchar(tolower(c));
	}
	else
	{
	    putchar(toupper(c));
	}
    }
    return 0;
}
