#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value)
{
    int temp;

    printf("Enter a positive number: ");
    if (scanf("%d", &temp) == 1 && temp > 0)
    {
        *value = temp;
        return true;
    }

    printf("Incorrect input\n");
    while (getchar() != '\n');
    
    return false;
};

int main(void)
{
    int incorrect_count = 0;

    while (incorrect_count < 3)
    {
        printf("Guess how much money I have!\n");

        int money;
        bool positive = read_positive(&money);

        if (positive)
            printf("You didn't get it right. I have %d euros.\n", money * 2 + 20);
        else
            incorrect_count++;
    }

    printf("I give up! See you later!\n");
    return 0;
}