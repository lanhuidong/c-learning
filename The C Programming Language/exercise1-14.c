#include <stdio.h>
#define MAX_WORD_LENGTH 26
/* Only statistics letters*/
main()
{
    int wordcount[MAX_WORD_LENGTH];
    int i, j;
    for(i = 0; i < MAX_WORD_LENGTH; i++)
    {
        wordcount[i] = 0;
    }
    int length, max;
    max = 0;
    length = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if( c >= 'a' && c <= 'z' )
	{
	    wordcount[c - 'a'] = wordcount[c - 'a'] + 1;
	}
	if(c >= 'A' && c <= 'Z')
	{
	    wordcount[c - 'A'] = wordcount[c - 'A'] + 1;
	}
    }

    for (i = 0; i < MAX_WORD_LENGTH; i++)
    {
        if (max < wordcount[i])
	{
	    max = wordcount[i];
	}
    }
    
    putchar('\n');
    printf("histogram with the bars horizontal:\n");
    for (i = 'A'; i < 'Z' + 1; i++)
    {
        printf("%c | ", i);
	for (j = 0; j < wordcount[i - 'A']; j++)
	{
	    putchar('*');
	}
	putchar('\n');
    }

    putchar('\n');
    printf("histogram with the bars vertical:\n");
    for (i = max; i > 0 ; i--)
    {
        for (j = 'A'; j < 'Z' + 1; j++ )
	{
	    putchar(' ');
	    if(i <= wordcount[j - 'A'])
	    {
	        putchar('*');
	    }
            else
	    {
	        putchar(' ');
            }
	}
	putchar('\n');
    }
    for (i = 'A'; i < 'Z' + 1; i++)
    {
        printf("%2c", i);
    }
    putchar('\n');
}
