#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    while (true)
    {
        char user_input[100];

        printf("Enter string: ");
        fgets(user_input, sizeof(user_input), stdin);

        size_t len = strlen(user_input);

        if (len > 0 && user_input[len - 1] == '\n')
        {
            user_input[len - 1] = '\0';
            len--;
        }
        printf("The size is %zu\n", len);

        if (strcmp(user_input, "stop") == 0)
        {
            printf("Program stopped\n");
            break;
        }        
    }
    

    return 0;
}