#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../utils.h"

int roll_dice(int max)
{
    unsigned int seed = time(0);
    int min = 1;
    return rand_r(&seed) % (max - min + 1) + min;
}

int main(void)
{
    const char *menu = "Operations:\n"
                        "(1) Roll D6\n"
                        "(2) Roll D10\n"
                        "(3) Quit\n"
                        "Enter opertaion (1 - 3): ";

    while(true)
    {
        int operation = validate_int_input(menu);

        if (operation == 1)
        { printf("You rolled %d\n\n", roll_dice(6)); }

        if (operation == 2)
        { printf("You rolled %d\n\n", roll_dice(10)); }

        if (operation == 3)
        {
            printf("Bye bye!\n");
            break;
        }
    }


    return 0;
}