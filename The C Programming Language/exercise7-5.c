#include <stdio.h>
#include <stdarg.h>
#define MAXLINE 100

void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int *ival;
    unsigned int *uival;
    double *dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
	{
	    continue;
	}
	switch (*++p)
	{
	    case 'd':
	        ival = va_arg(ap, int *);
		scanf("%d", ival);
		break;
	    case 'i':
	        ival = va_arg(ap, int *);
		scanf("%i", ival);
		break;
	    case 'o':
	        uival = va_arg(ap, unsigned int *);
		scanf("%o", uival);
		break;
	    case 'u':
	        uival = va_arg(ap, unsigned int *);
		scanf("%u", uival);
		break;
	    case 'x':
	        uival = va_arg(ap, unsigned int *);
		scanf("%x", uival);
		break;
	    case 'c':
	        sval = va_arg(ap, char *);
		scanf("%c", sval);
		break;
	    case 's':
	        sval = va_arg(ap, char *);
		scanf("%s", sval);
		break;
	    case 'e':
	        dval = va_arg(ap, double *);
		scanf("%e", dval);
		break;
	    case 'f':
	        dval = va_arg(ap, double *);
		scanf("%f", dval);
		break;
	    case 'g':
	        dval = va_arg(ap, double *);
		scanf("%g", dval);
		break;
	    default:
		break;
	}
    }
    va_end(ap);
}

int main(int argc, char *argv[])
{
    char name[MAXLINE];
    int age;
    float salary;
    minscanf("%s %d %f", name, &age, &salary);
    printf("My name is %s, age %d, salary %f\n", name, age, salary);
    return 0;
}
