#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../utils.h"

int main(void)
{
    char file_path[] = "Ex_21/";
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

    char line_content[1024];
    while (fgets(line_content, sizeof(line_content), read_ptr))
    {
        if (line_content[0] == '$')
        {
            int char_index = 1;
            int valid_line = 0;
            int checksum_value = 0;

            while (line_content[char_index] != '\n')
            {
                if (line_content[char_index] == '*') {
                    valid_line = 1;
                    break;
                }
                checksum_value ^= line_content[char_index];
                char_index++;
            }
            if (valid_line)
            {
                int checksum_compare = (int)strtol(&line_content[char_index+1], NULL, 16);

                if (checksum_value == checksum_compare) {
                    printf("[ OK ] %s", line_content);
                } else {
                    printf("[FAIL] %s", line_content);
                }
            }
        }
    }
    

    return 0;
}