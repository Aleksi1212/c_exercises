#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils.h"

int main(void)
{
    srand(time(NULL));

    while (1)
    {
        int num = validate_int_input("Enter a number betweem 0-15 (negative to stop): ");
        if (num < 0)
            break;

        int rand_num = rand();
        printf("Random num: %x\n", rand_num);

        rand_num >>= num;
        rand_num &= ~0x3F;
        printf("Modified num: 0x%02x\n", rand_num);
    }
    
    return 0;
}