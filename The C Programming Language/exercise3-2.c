#include <stdio.h>
#define MAXLINE 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(int argc, char *argv[])
{
    char t[MAXLINE];
    char t1[MAXLINE];
    char s[] = "a	b";
    char s1[]="a\\tb\\n";
    escape(s, t);
    printf("%s\n", t);
    unescape(s1, t1);
    printf("%s", t1);
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    for(i = 0, j = 0; s[i] != '\0'; i++, j++)
    {
        switch (s[i])
	{
	    case '\t':
	        t[j++] = '\\';
		t[j] = 't';
		break;
	    case '\n':
	        t[j++] = '\\';
		t[j] = 'n';
		break;
	    default:
	        t[j] = s[i];
		break;
	}
    }
    t[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++, j++)
    {
        if (s[i] == '\\')
	{
	    switch (s[i + 1])
	    {
	        case 't':
		    t[j] = '\t';
		    i++;
		    break;
		case 'n':
		    t[j] = '\n';
		    i++;
		    break;
		default:
		    t[j] = s[i];
		    break;
	    }
	}
	else
	{
	    t[j] = s[i];
	}
    }
    t[j] = '\0';
}
