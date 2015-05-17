#include <stdio.h>
#define MAXLINE 1000

int main(int argc, char *argv[])
{
    FILE *fp;
    char *filename, *line;
    char content[MAXLINE];
    int i, count;
    i = 1;
    count = 0;
    while (i < argc)
    {
        filename = argv[i];
	if ((fp = fopen(filename, "r")) != NULL)
	{
	    ++count;
	    printf("page %d: filename: %s\n", count, filename);
	    while ((line = fgets(content, MAXLINE, fp)) != NULL)
	    {
	        fputs(line, stdout);
	    }
	}
        ++i;
    }
    fclose(fp);
    return 0;
}
