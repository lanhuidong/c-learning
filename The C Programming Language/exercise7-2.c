#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLINELENGTH 10  /*每行的长度*/

int main(int argc, char *argv[])
{
    char c;
    char *option;
    char *format;
    char string[10];
    int state,  position, count, i;
    position = 0;
    option = *++argv;
    if(argc == 1)
    {
        return 1;
    }
    else
    {
        if (strcmp(option, "oct") == 0)
	{
	    format = "%o";
	}
	else
	{
	    format = "%x";
	}
    }
    while ((c = getchar()) != EOF)
    {
	    if (!isgraph(c))
	    {
	         count = sprintf(string, format, c);
	 	 for (i = 0; i < count; i++)
		 {
		      if (position == MAXLINELENGTH)
		      {
		          putchar('\n');
		          position = 0;
		      }
		      putchar(*(string + i));
		      ++position;
		  }
	     }
	     else
	     {
	          if (position ==  MAXLINELENGTH)
		  {
		      putchar('\n');
		      position = 0;
		  }
	          putchar(c);
	          ++position;
	     }
    }
    return 0;
}
