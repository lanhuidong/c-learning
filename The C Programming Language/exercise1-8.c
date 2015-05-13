#include <stdio.h>

main()
{
    int count;
    char c;
    
    count = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t' || c == '\n' || c==' ')
	{
	    ++count;
	}
    }
    printf("%d\n", count);
}
