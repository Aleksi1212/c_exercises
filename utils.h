#ifndef UTILS_H
#define UTILS_H

float validate_float_input(const char *message);
int validate_int_input(const char *message);
void validate_char_input(const char* message, char *string, int maxLen);
void remove_new_line(char *str);
int is_file_extension(const char *file_name, const char *extension);


#endif