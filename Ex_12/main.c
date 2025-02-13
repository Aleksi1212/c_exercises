#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../utils.h"

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

int main(void)
{
    
    while (true)
    {
        char string[100];
        char word[100];

        validate_char_input("Give a string", string, sizeof(string));
        validate_char_input("Give a word to find in the string", word, sizeof(word));

        if (strcmp(word, "stop") == 0)
        {
            printf("Program stopped\n");
            break;
        }

        int count = count_words(string, word);
        if (count > 0)
            printf("Found %d instances of %s in the string\n\n", count, word);
        else
            printf("%s was not found in the string\n\n", word);

    }

    return 0;
}
