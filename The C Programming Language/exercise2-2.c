#include <stdio.h>

main()
{
    int lim, i;
    lim = 100;
    i = 0;
    char s[lim];
    char c;
    while ((c = getchar()) != EOF)
    {
        if (i >= lim - 1)
	{
	    break;
	}
	if (c == '\n')
	{
	    break;
	}
	s[i] = c;
	++i;
    }
}
