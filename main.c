#include <stdio.h>
void fahrenheit(float *temp, float *convert, int num);
void celsius(float *temp, float *convert, int num);

int main()
{
    int option, num;

    printf("===TEMPERATURE CONVERTER===\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");

    printf("Choose conversion (1 or 2): ");
    scanf("%d", &option);

    printf("How many temperatures do you want to convert: ");
    scanf("%d", &num);

    float temperatures[num], converted[num];

    printf("\nEnter %d temperatures:\n", num);
    for (int i = 0; i < num; i++) {
        printf("Temperature #%d: ", i + 1);
        scanf("%f", &temperatures[i]);
    }

    printf("\n===CONVERTED TEMPERATURES===\n");

    if (option == 1) {
        fahrenheit(temperatures, converted, num);
    } else if (option == 2) {
        celsius(temperatures, converted, num);
    }

    return 0;
}

void fahrenheit(float *temp, float *convert, int num)
{

    for (int i = 0; i < num; i++) {
        *(convert + i) = (1.8 * *(temp + i) + 32);
        printf("%.2f°C - %.2f°F\n", *(temp + i), *(convert + i));
    }

}

void celsius(float *temp, float *convert, int num)
{
    for (int i = 0; i < num; i++) {
        *(convert + i) = (5.0/9.0) * (*(temp + i) - 32);
        printf("%.2f°F - %.2f°C\n", *(temp + i), *(convert + i));
    }

}
