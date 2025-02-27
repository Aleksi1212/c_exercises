#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../utils.h"

#define ARRAY_SIZE 40

struct Menu_item
{
    char name[50];
    double price;
};

int main(void)
{
    char file_path[] = "Ex_15/";
    char file_name[100];

    while (1)
    {
        validate_char_input("Give a file name", file_name, sizeof(file_name));
        if (is_file_extension(file_name, ".txt"))
            break;
        printf("Must be a .txt file.\n");
    }
    
    strcat(file_path, file_name);

    FILE *read_ptr;
    read_ptr = fopen(file_path, "r");

    if (read_ptr == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", file_path);
        return 1;
    }

    struct Menu_item menu_arr[ARRAY_SIZE];
    
    int num = 0;
    char line_content[100];

    while (fgets(line_content, 100, read_ptr) && num <= ARRAY_SIZE)
    {
        remove_new_line(line_content);
        
        char delimiter[] = ";";
        char *token;
        int token_count = 0;

        token = strtok(line_content, delimiter);

        while (token != NULL && token_count < 2)
        {
            if (token_count == 0) {
                snprintf(menu_arr[num].name, sizeof(menu_arr[num].name), "%s", token);
            }
            if (token_count == 1) {
                menu_arr[num].price = atof(token);
            }

            token = strtok(NULL, delimiter);
            token_count++;
        }
        num++;
    }
    fclose(read_ptr);

    printf("\n%-8s%s\n", "Price", "Name");
    for (int i = 0; i < num; i++)
    {
        printf("%-8.2f%s\n", menu_arr[i].price, menu_arr[i].name);
    }
    
    return 0;
}