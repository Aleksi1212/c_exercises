#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils.h"

#define ARRAY_SIZE 20

int find_first(const unsigned int *array, unsigned int what)
{
    int current_index = 0;
    while (array[current_index] != 0)
    {
        if (array[current_index] == what)
            return current_index;
        else
            current_index++;
    }
    return -1;
}

int main(void)
{
    int array[ARRAY_SIZE];
    
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE-1; i++)
    {
        array[i] = (rand() % (20 - 2)) + 1;
    }
    array[ARRAY_SIZE-1] = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d\n", array[i]);
    }

    int num_to_find = validate_int_input("Enter a number to find in the list (0 to stop): ");
    while (num_to_find != 0)
    {
        int found_index = find_first(array, num_to_find);
        if (found_index != -1)
            printf("Found number %d at index %d in the list.\n", num_to_find, found_index);
        else
            printf("Couldn't find number %d in the list\n", num_to_find);

        num_to_find = validate_int_input("Enter a number to find in the list (0 to stop): ");
    }

    return 0;
}