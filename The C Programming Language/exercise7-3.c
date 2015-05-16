#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    unsigned int uval;
    char cval;
    double dval;
    void *pv;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
	{
	    putchar(*p);
	    continue;
	}
	switch (*++p)
	{
	    case 'd':
	        ival = va_arg(ap, int);
		printf("%d", ival);
		break;
	    case 'i':
	        ival = va_arg(ap, int);
		printf("%i", ival);
		break;
	    case 'o':
	        uval = va_arg(ap, unsigned int);
		printf("%o", uval);
		break;
	    case 'x':
	        uval = va_arg(ap, unsigned int);
		printf("%x", uval);
		break;
	    case 'X':
	        uval = va_arg(ap, unsigned int);
		printf("%X", uval);
		break;
	    case 'u':
	        uval = va_arg(ap, unsigned int);
		printf("%u", uval);
		break;
	    case 'c':
	        cval = va_arg(ap, int);
		printf("%c", cval);
		break;
            case 'f':
	        dval = va_arg(ap, double);
		printf("%f", dval);
		break;
            case 's':
	        for (sval = va_arg(ap, char *); *sval; sval++)
		{
		    putchar(*sval);
		}
		break;
            case 'e':
	        dval = va_arg(ap, double);
		printf("%e", dval);
		break;
	    case 'E':
	        dval = va_arg(ap, double);
		printf("%E", dval);
		break;
	    case 'g':
	        dval = va_arg(ap, double);
		printf("%g", dval);
		break;
	    case 'G':
	        dval = va_arg(ap, double);
		printf("%G", dval);
		break;
	    case 'p':
	        pv = va_arg(ap, void *);
		printf("%p", pv);
		break;
            case '%':
	        printf("%%");
		break;
	    default:
	        putchar(*p);
		break;
	}
    }
    va_end(ap);
}

int main()
{
    minprintf("name=%s, age=%d, salary=%f\n", "lan", 28, 12000.0);
    return 0;
}
