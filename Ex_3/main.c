#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"

int main(void)
{
    int student_amount = validate_int_input("How many students: ");

    int* students_array = (int*)calloc(student_amount, sizeof(int));
    for (int i = 0; i < student_amount; i++)
    {
        students_array[i] = -1;
    }

    int student_number = -1;
    while (true)
    {
        if (student_number == -1)
        {
            char student_number_q[100];
            snprintf(student_number_q, sizeof(student_number_q), "\nEnter student number (1 - %d) or 0 to stop: ", student_amount);

            student_number = validate_int_input(student_number_q);

            if (student_number == 0) { break; }

            if (student_number > student_amount || student_number < 0)
            {
                printf("Invalid student number!");
                continue;
            }
        }
        
        char student_grade_q[100];
        snprintf(student_grade_q, sizeof(student_grade_q), "Enter grade (0 - 5) for student %d or -1 to cancel: ", student_number);

        int student_grade = validate_int_input(student_grade_q);

        if (student_grade > 0 && student_grade <= 5)
        {
            students_array[student_number - 1] = student_grade;
        }
        else if (student_grade > 5)
        {
            printf("Invalid grade!\n");
            continue;
        }

        student_number = -1;
    }

    printf("\n%-10s %s\n", "Student", "Grade");
    for (int i = 0; i < student_amount; i++)
    {
        if (students_array[i] < 0)
        {
            printf("%-10d %s\n", i+1, "N/A");
        }
        else
        {
            printf("%-10d %d\n", i+1, students_array[i]);
        }
    }

    return 0;
}