#include <stdio.h>

main()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
	{
	    putchar('\n');
	}
	else
	{
	    putchar(c);
	}
    }
}
