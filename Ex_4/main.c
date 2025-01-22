#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>


int read_integer(void)
{
    int output;

    printf("Enter positive numbers or negative to stop: ");

    while (scanf("%d", &output) != 1)
    {
        printf("Invalid input\n");
        printf("Enter positive numbers or negative to stop: ");
        while (getchar() != '\n');
    }

    return output;
}

int main(void)
{
    int arr_size = 0;
    float* num_arr = (float*)calloc(arr_size, sizeof(float));

    while (true)
    {
        int num = read_integer();
        if (num > 0)
        {
            num_arr[arr_size] = num;
            arr_size++;
            num_arr = realloc(num_arr, arr_size * sizeof(float));
        }
        else { break; }
    }

    float sum = 0;
    for (int i = 0; i < arr_size; i++)
    {
        sum += num_arr[i];
    }

    printf("You entered %d positive numbers. The average is: %.2f\n", arr_size, sum / (float)(arr_size));
    
}