#include <stdio.h>
#include <string.h>
#include "../utils.h"

#define ARRAY_SIZE 40

struct menu_item
{
    char name[50];
    double price;
};

int main(void)
{
    char file_path[] = "Ex_15/";
    char file_name[100];

    validate_char_input("Give a file name", file_name, sizeof(file_name));
    strcat(file_path, file_name);

    FILE *read_ptr;
    read_ptr = fopen(file_path, "r");

    if (read_ptr == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", file_path);
        return 1;
    }

    struct menu_item menu_arr[ARRAY_SIZE];

    int num = 0;
    char line_content[100];

    while (fgets(line_content, 100, read_ptr) && num <= ARRAY_SIZE)
    {
        remove_new_line(line_content);
        
    }
    

    return 0;
}