#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char *prog, *filename1, *filename2, *l1, *l2;
    char line1[MAXLINE], line2[MAXLINE];
    int linenum;
    linenum = 0;
    prog = argv[0];
    filename1 = argv[1];
    filename2 = argv[2];

    if (argc == 3 && (fp1 = fopen(filename1, "r")) != NULL && (fp2 = fopen(filename2, "r")) != NULL)
    {
        while((l1 = fgets(line1, MAXLINE, fp1)) != NULL && (l2 = fgets(line2, MAXLINE, fp2)) != NULL)
	{
	    ++linenum;
	    if (strcmp(l1, l2) != 0)
	    {
	        printf("%s and %s are diff from line %d\n", filename1, filename2, linenum);
		printf("%s:", filename1);
		fputs(l1, stdout);
		printf("%s:", filename2);
		fputs(l2, stdout);
		break;
	    }
	}
        ++linenum;
	if (l1 == NULL && (l2 = fgets(line2, MAXLINE, fp2)) != NULL)
	{
	    printf("%s and %s are diff from line %d\n", filename1, filename2, linenum);
	    printf("%s:", filename2);
	    fputs(l2, stdout);
	}
	else if (l1 != NULL && l2 == NULL)
	{
	    printf("%s and %s are diff from line %d\n", filename1, filename2, linenum);
	    printf("%s:", filename1);
	    fputs(l1, stdout);
	}
        fclose(fp1);
        fclose(fp2);
    }
    else 
    {
        printf("Usage:%s file1 file2\n", prog);
    }
    return 0;
}
