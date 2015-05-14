#include <stdio.h>

float f2c(float);

main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit Celsius\n");
    while (fahr <= upper) {
	printf("%10.0f %7.1f\n", fahr, f2c(fahr));
	fahr = fahr + step;
    }
}

float f2c(float fahr){
    float celsius;
    celsius  = ( 5.0 / 9.0) * (fahr - 32.0);
    return celsius;
}
