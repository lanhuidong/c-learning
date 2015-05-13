#include <stdio.h>
#define MAX_WORD_LENGTH 10

main()
{
    int wordcount[MAX_WORD_LENGTH + 1];
    int i, j;
    for(i = 0; i < MAX_WORD_LENGTH + 1; i++)
    {
        wordcount[i] = 0;
    }
    int length, max;
    max = 0;
    length = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
	{
            if (length > 10)
	    {
	        wordcount[0] = wordcount[0] + 1;
	    }
	    else 
	    {
	        wordcount[length] = wordcount[length] + 1;
	    }
	    length = 0;
	}
	else
	{
	    ++length;
	}
    }
    for (i = 0; i < MAX_WORD_LENGTH + 1; i++)
    {
        if (max < wordcount[i])
	{
	    max = wordcount[i];
	}
    }
    
    putchar('\n');
    printf("histogram with the bars horizontal:\n");
    for (i = 1; i < MAX_WORD_LENGTH + 1; i++)
    {
        printf("%3d | ", i);
	for (j = 0; j < wordcount[i]; j++)
	{
	    putchar('*');
	}
	putchar('\n');
    }

    printf(">10 | ");
    for (j = 0; j < wordcount[0]; j++)
    {
        putchar('*');
    }

    putchar('\n');
    printf("histogram with the bars vertical:\n");
    for (i = max; i > 0 ; i--)
    {
        for (j = 1; j < MAX_WORD_LENGTH + 1; j++ )
	{
	    putchar(' ');
	    if(i <= wordcount[j])
	    {
	        putchar('*');
	    }
            else
	    {
	        putchar(' ');
            }
	    putchar(' ');
	}
        putchar(' ');
	if (i <= wordcount[0])
	{
	    putchar('*');
	}
	else
	{
	    putchar(' ');
	}
        putchar(' ');
	putchar('\n');
    }
    for (i = 1; i < MAX_WORD_LENGTH + 1; i++)
    {
        printf("%2d ", i);
    }
    printf(">10");
    putchar('\n');
}
