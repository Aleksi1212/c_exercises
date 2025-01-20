#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

int main(void)
{
    int student_amount = validate_int_input("How many students: ");

    int* sutdents_array = (int*)calloc(student_amount, sizeof(int));
    for (int i = 0; i < student_amount; i++)
    {
        sutdents_array[i] = -1;
    }

    int student_number = -1;
    while (student_number != 0)
    {
        if (student_number == -1)
        {
            char student_number_q[100];
            sprintf(student_number_q, "\nEnter student number (1 - %d) or 0 to stop: ", student_amount);

            student_number = validate_int_input(student_number_q);

            if (student_number > student_amount || student_number < 0)
            {
                printf("Invalid student number!");
                continue;
            }
        }
        
        char student_grade_q[100];
        sprintf(student_grade_q, "Enter grade (0 - 5) for student %d or -1 to cancel: ", student_number);

        int student_grade = validate_int_input(student_grade_q);

        if (student_grade > 5)
        {
            printf("Invalid grade!\n");
            continue;
        }

        


    }
    



    return 0;
}