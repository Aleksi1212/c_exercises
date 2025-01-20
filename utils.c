#include <stdio.h>
#include "utils.h"

float validate_float_input(const char *message)
{
    float output;

    printf("%s", message);

    while (scanf("%f", &output) != 1)
    {
        printf("Invalid input\n");
        printf("%s", message);
        while (getchar() != '\n');
    }

    return output;
}

int validate_int_input(const char *message)
{
    int output;

    printf("%s", message);

    while (scanf("%d", &output) != 1)
    {
        printf("Invalid input\n");
        printf("%s", message);
        while (getchar() != '\n');
    }

    return output;
}
