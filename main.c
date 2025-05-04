#include <stdio.h>
#include <stdlib.h>

void fahrenheit(float *t, float *c, int num);
void celsius(float *t, float *c, int num);

int main()
{

    int num, opt;

    printf("===Temperature Converter===\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");

    printf("Enter conversion (1 or 2): ");
    scanf("%d", &opt);

    printf("\nEnter the recorded temperature for the week (max. 7): ");
    scanf("%d", &num);

    if (num > 7 || num < 1) {
        printf("\nInvalid Input!\n");
        printf("Exiting Program...\n");
        return 1;
    }

    float *temperatures = calloc(num, sizeof(float)), *converted = calloc(num, sizeof(float));

    if (!temperatures || !converted) {
        fprintf(stderr, "Memory Allocation failed!\n");
        free(temperatures);
        free(converted);
        return 1;
    }

    if (opt == 1) {
        printf("Enter the temperatures in Celsius:\n");
    } else if (opt == 2) {
        printf("Enter the temperatures in Fahrenheit:\n");
    }

    for (int i = 0; i < num; i++) {
        printf("Temperature for Day #%d: ", i + 1);
        scanf("%f", &temperatures[i]);
    }

    printf("\n===Converted Temperatures===\n");

    if (opt == 1) {
        fahrenheit(temperatures, converted, num);
    } else if (opt == 2) {
        celsius(temperatures, converted, num);
    } else {
        printf("\nInvalid conversion option!\n");
        free(temperatures);
        free(converted);
        return 1;
    }

    return 0;
}

void fahrenheit(float *t, float *c, int num)
{
    for (int i = 0; i < num; i++) {
        *(c+i) = (1.8 * *(t+i) + 32);

        printf("%.2fC -> %.2fF\n", *(t+i), *(c+i));
    }
}

void celsius(float *t, float *c, int num)
{
    for (int i = 0; i < num; i++) {
        *(c+i) = (5.0/9.0) * (*(t+i) - 32);

        printf("%.2fF -> %.2fC\n", *(t+i), *(c+i));
    }
}

