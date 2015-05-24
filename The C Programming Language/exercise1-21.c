#include <stdio.h>
#define SPACENUM 4

int main(int argc, char *argv[])
{
    char c;
    int space, i;
    space = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
	{
	    ++space;
	    if (space == 4)
	    {
	        putchar('\t');
	        space = 0;
	    }
	}
	else
	{
	    if (space > 0)
	    {
	        for (i = 0; i < space; i++)
		{
		    putchar(' ');
		}
	    }
	    putchar(c);
	    space = 0;
	}
    }
    return 0;
}
