#include <stdio.h>
#include <string.h>

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
    char text[80] = "I am so tired of Python. C is much better language";
    int count = replace_char(text, "e3");

    if (count > 0)
        printf("%d\n", count);
    else
        printf("String was not modified\n");
    
    return 0;
}