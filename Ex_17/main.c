#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../utils.h"

bool password_gen(char *password, int password_size, const char *word)
{
    if (!password || !word)
        return false;

    int word_len = strlen(word);
    int required_size = (word_len * 2) + 1;

    if (password_size < required_size + 1)
        return false;

    for (int i = 0; i < word_len; i++)
    {
        password[i * 2] = (char)(33 + rand() % 94);
        password[(i * 2) + 1] = word[i];
    }

    password[required_size] = '\0';

    return true;
}

int main(void)
{
    srand(time(NULL));

    while (true)
    {
        char word[32];
        validate_char_input("Enter a word (\"stop\" to stop): ", word, sizeof(word));
        
        if (strcmp(word, "stop") == 0)
            break;
        
        char password[(sizeof(word) * 2) + 1];
        bool generated = password_gen(password, sizeof(password), word);

        if (generated)
            printf("%s\n", password);
        else
            printf("Error generating password.\n");
    }


    return 0;
}