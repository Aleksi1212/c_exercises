#include <stdio.h>
#include <string.h>
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

void validate_char_input(const char *message, char *string, int maxLen)
{
    do
    {
        printf("%s\n", message);
        fgets(string, maxLen, stdin);

        size_t len = strlen(string);
        if (len > 0 && string[len - 1] == '\n')
        {
            string[len - 1] = '\0';
        }
    } while (strlen(string) == 0);
    
}
