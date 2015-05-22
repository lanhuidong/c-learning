#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVALUE 100

void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    int i;
    double op2;
    char s[MAXOP];
    i = 1;
    printf("total commod line arguments:%d\n", argc);
    while (i < argc)
    {
        switch (*(*++argv))
	{
	    case '+':
	        push(pop() + pop());
		break;
	    case '*':
	        push(pop() * pop());
		break;
	    case '-':
	        op2 = pop();
		push(pop() - op2);
		break;
	    case '/':
	        op2 = pop();
		if (op2 != 0.0)
		    push(pop() / op2);
		else
		    printf("error: zero divisor\n");
		break;
	    default:
	        push(atof(*argv));
	        break;
	}
	i++;
    }
   printf("\t%.8g\n", pop());
    return 0;
}

int sp = 0;
double val[MAXVALUE];
void push(double f)
{
    if (sp < MAXVALUE)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
	return 0.0;
    }
}
