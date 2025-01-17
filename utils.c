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