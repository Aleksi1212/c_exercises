#include <stdio.h>
#include <string.h>
#include "../utils.h"

int replace_char(char *str, const char *repl)
{
    int str_length = strlen(str);
    int repl_length = strlen(repl);

    int count = 0;

    for (int i = 0; i < str_length; i++)
    {
        if (str[i] == repl[0])
        {
            str[i] = repl[repl_length - 1];
            count++;
        }
    }

    printf("%s\n", str);

    return count;
}

int main(void)
{
    char string[100];
    char substr[3];

    validate_char_input("Enter a string:", string, sizeof(string));
    validate_char_input("Enter a substring of length 2:", substr, sizeof(substr));

    int count = replace_char(string, substr);

    if (count > 0)
        printf("%d\n", count);
    else
        printf("String was not modified\n");
    
    return 0;
}