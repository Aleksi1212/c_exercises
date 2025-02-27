#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../utils.h"

#define ARRAY_SIZE 100
#define MAX_LINE_SIZE 80

int main(void)
{
    char file_path[] = "Ex_14/";
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
    
    char **lines_arr = malloc(ARRAY_SIZE * sizeof(char *));
    char line[1000];
    
    int num = 0;
    while (fgets(line, 1000, read_ptr) && num <= ARRAY_SIZE)
    {
        remove_new_line(line);

        lines_arr[num] = malloc((MAX_LINE_SIZE + 1) * sizeof(char));
        
        int j = 0;
        while (line[j])
        {
            line[j] = toupper(line[j]);
            j++;
        }
        
        strncpy(lines_arr[num], line, MAX_LINE_SIZE);
        num++;
    }
    
    fclose(read_ptr);

    FILE *write_ptr;
    write_ptr = fopen(file_path, "w");

    if (write_ptr == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", file_path);
        return 1;
    }

    for (int i = 0; i < num; i++)
    {
        fprintf(write_ptr, "%s\n", lines_arr[i]);
    }
    fclose(write_ptr);
    printf("Success!!!\n");

    return 0;
}