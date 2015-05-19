#include <stdio.h>

int strend(char *s, char *t);

int main(int argc, char *argv[])
{
    char s[] = "javascript";
    char t[] = "script";
    char t1[] = "python";
    if (strend(s, t))
    {
        printf("%s is end of %s\n", s, t);
    }
    else
    {
        printf("%s is not end of %s\n", s, t);
    }
    if (strend(s, t1))
    {
        printf("%s is end of %s\n", s, t1);
    }
    else
    {
        printf("%s is not end of %s\n", s, t1);
    }
    return 0;
}

int strend(char *s, char *t)
{
    int slen, tlen, i;
    char *ss, *tt;
    ss = s;
    tt = t;
    slen = tlen = 0;
    while (*s++ != '\0')
    {
        ++slen;
    }
    while (*t++ != '\0')
    {
        ++tlen;
    }
    if (tlen <= slen)
    {
        for (i = 0; i < tlen; i++)
	{
	    if (*(ss + (slen-tlen + i)) != *(tt + i))
	    {
	        break;
	    }
	}
	if (i == tlen)
	{
	    return 1;
	}
    }
    return 0;
}
