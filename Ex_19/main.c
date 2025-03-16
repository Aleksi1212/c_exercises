#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../utils.h"

#define ARRAY_SIZE 40

typedef struct
{
    char name[50];
    double price;
} Menu_item;

int name_compare(const void* a, const void* b)
{
    return strcmp(((Menu_item *)a)->name, ((Menu_item *)b)->name);
}
int price_compare(const void* a, const void* b)
{
    return (((Menu_item *)a)->price - ((Menu_item*)b)->price);
}

int main(void)
{
    char file_path[] = "Ex_19/";
    char file_name[100];


    while (1)
    {
        validate_char_input("Give a file name: ", file_name, sizeof(file_name));
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

    Menu_item menu_arr[ARRAY_SIZE];
    
    int menu_size = 0;
    char line_content[100];

    while (fgets(line_content, 100, read_ptr) && menu_size <= ARRAY_SIZE)
    {
        remove_new_line(line_content);
        
        char delimiter[] = ";";
        char *token;
        int token_count = 0;

        token = strtok(line_content, delimiter);

        while (token != NULL && token_count < 2)
        {
            if (token_count == 0) {
                snprintf(menu_arr[menu_size].name, sizeof(menu_arr[menu_size].name), "%s", token);
            }
            if (token_count == 1) {
                menu_arr[menu_size].price = atof(token);
            }

            token = strtok(NULL, delimiter);
            token_count++;
        }
        menu_size++;
    }
    fclose(read_ptr);

    while (1)
    {
        int sort = validate_int_input("Sort menu by (1)name or (2)price: ");

        if (sort == 1) {
            qsort(menu_arr, menu_size, sizeof(Menu_item), name_compare);
            break;
        }
        if (sort == 2) {
            qsort(menu_arr, menu_size, sizeof(Menu_item), price_compare);
            break;
        }
    }
    
    printf("\n%-8s%s\n", "Price", "Name");
    for (int i = 0; i < menu_size; i++)
    {
        printf("%-8.2f%s\n", menu_arr[i].price, menu_arr[i].name);
    }
    
    return 0;
}