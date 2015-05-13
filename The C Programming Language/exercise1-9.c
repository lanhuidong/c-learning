#include <stdio.h>

main()
{
    int state;
    state = 0;
    char c;
    while((c = getchar()) != EOF)
    {
        if(c == '\t' || c == ' ')
	{
	    if(state == 0)
	    {
	        state = 1;
                putchar(' ');
	    }
	}
	else
	{
            putchar(c);
	    state = 0;
	}
    }
}
