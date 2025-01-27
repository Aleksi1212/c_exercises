#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 15

void print_numbers(const int *array, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%8d\n", array[i]);
    }
}

int main(void)
{
    int array[ARRAY_SIZE];

    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand();
    }
    
    print_numbers(array, ARRAY_SIZE);
    return 0;
}