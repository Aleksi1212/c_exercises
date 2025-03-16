#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "debug.h"
#include "../utils.h"

int main(void)
{
    
    while (1)
    {
        int debug_level = validate_int_input("Enter debug level (0 - 4): ");
        if (debug_level >= 0 && debug_level <= 4) {
            set_debug_level(debug_level);
            break;
        }
    }
    
    srand(time(NULL));
    for (int i = 1; i <= 5; i++)
    {
        int rand_debug_level = rand() % (4 + 1 - 0) + 0;
        dprintf(rand_debug_level, "Debug message %d\n", i);
    }

    return 0;
}