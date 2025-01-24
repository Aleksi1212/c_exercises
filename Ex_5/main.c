#include <stdio.h>
#include <stdbool.h>

int read_range(int low, int high)
{
    int value;
    
    printf("Enter value between (%d - %d): ", low, high);
    while (scanf("%d", &value) != 1 || (value > high || value < low))
    {
        printf("Invalid input. Enter a value between (%d - %d): ", low, high);
        while (getchar() != '\n');
    }
    
    return value;
}

int main(void)
{
    int player_result;

    printf("Lets play!\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Roll a die and enter your result.\n");
        player_result = read_range(1, 6);
        
        if (player_result < 6)
        {
            printf("I got %d. I win!\n", player_result+1);
        }
        else {
            printf("I got 6. It is a tie!\n");
            break;
        }
    }

    printf("Better luck next time. Bye!\n");
    
    return 0;
}