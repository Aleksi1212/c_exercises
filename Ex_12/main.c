#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int count_words(const char* str, const char *word)
{
    int count = 0;

    str = strstr(str, word);
    while (str != NULL)
    {
        str += strlen(word);
        count++;
        str = strstr(str, word);

    }

    return count;
}

void validate_char(const char* message, char* string, int maxLen)
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

int main(void)
{
    
    while (true)
    {
        char string[100];
        char word[100];

        validate_char("Give a string", string, sizeof(string));
        validate_char("Give a word to find in the string", word, sizeof(word));

        if (strcmp(word, "stop") == 0)
        {
            printf("Program stopped\n");
            break;
        }

        int count = count_words(string, word);
        if (count > 0)
            printf("Found %d instances of %s in the string\n", count, word);
        else
            printf("%s was not found in the string\n", word);

    }

    return 0;
}
