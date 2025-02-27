#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "../utils.h"

int main(void)
{
    char file_path[] = "Ex_13/";
    char file_name[100];

    while (1)
    {
        validate_char_input("Give a file name", file_name, sizeof(file_name));
        if (is_file_extension(file_name, ".txt"))
            break;
        printf("Must be a .txt file.\n");
    }
    strcat(file_path, file_name);

    FILE *file_ptr;
    file_ptr = fopen(file_path, "r");

    if (file_ptr == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", file_path);
        return 1;
    }

    int largest_number = INT_MIN;
    int smallest_number = INT_MAX;
    int number_count = 0;

    char file_content[100];
    while (fgets(file_content, 100, file_ptr))
    {
        remove_new_line(file_content);

        if (!isdigit(*file_content)) {
            continue;
        }
        
        int number = atoi(file_content);
        number_count++;

        if (number >= largest_number) {
            largest_number = number;
        }
        if (number <= smallest_number) {
            smallest_number = number;
        }
    }
    fclose(file_ptr);

    printf("\nData succesfully read from %s\n", file_path);
    printf("Count of numbers: %d\n", number_count);
    printf("Smallest number: %d\n", smallest_number);
    printf("Largest number: %d\n", largest_number);

    return 0;
}