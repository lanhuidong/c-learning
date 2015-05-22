#include <stdio.h>

static char daytab[2][13] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(int argc, char *argv[])
{
    int m, d, day;
    month_day(1988, 60, &m, &d);
    printf("1988年的第60天是%d月%d日\n", m, d);
    day = day_of_year(1988, m, d);
    printf("1988年的%d月%d日是1988年的第%d天\n", m, d, day);
    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month > 12 || month < 1)
    {
        printf("input month error.");
        return -1;
    }
    if (day >  *((*(daytab+leap)) + month) || day < 1)
    {
        printf("input day error.");
        return -1;
    }
    for (i = 1; i < month; i++)
        day += *((*(daytab+leap)) + i);
    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year %4 == 0 && year % 100 != 0 || year % 400 == 0;
    if ((leap == 1) && (yearday > 366 || yearday < 1))
    {
        printf("day must between 1 and 366");
        return -1;
    }
    else if((leap == 0) && (yearday > 365 || yearday < 1))
    {
        printf("day must between 1 and 365");
        return -1;
    }
    for (i = 1; yearday > *((*(daytab+leap))+i); i++)
        yearday -= *((*(daytab+leap))+i);
    *pmonth = i;
    *pday = yearday;
}
