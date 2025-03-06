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

void remove_new_line(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

void validate_char_input(const char *message, char *string, int maxLen)
{
    do
    {
        printf("%s", message);
        fgets(string, maxLen, stdin);
        remove_new_line(string);
    } while (strlen(string) == 0);
}

int is_file_extension(const char *file_name, const char *extension)
{
    const char *ext = strrchr(file_name, '.');

    return ext != NULL && strcmp(ext, extension) == 0;
}