#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    float bus_ticket_price;
    float taxi_trip_price;
    float money_amount;

    printf("Enter price of bus ticket: ");
    while (scanf("%f", &bus_ticket_price) != 1)
    {
        printf("Invalid input\n");
        printf("Enter price of bus ticket: ");
        while (getchar() != '\n');
    }

    printf("Enter price of taxi: ");
    while (scanf("%f", &taxi_trip_price) != 1)
    {
        printf("Invalid input\n");
        printf("Enter price of taxi: ");
        while (getchar() != '\n');
    }

    printf("How much money you have: ");
    while (scanf("%f", &money_amount) != 1)
    {
        printf("Invalid input\n");
        printf("How much money you have: ");
        while (getchar() != '\n');
    }

    while (money_amount >= bus_ticket_price || money_amount >= taxi_trip_price)
    {
        int* selected_form_of_transportation = (int*)malloc(sizeof(int));

        printf("\nYou have %2.f money left", money_amount);
        printf("\nDo you wan to take");
        printf("\n1) bus (%2.f)", bus_ticket_price);
        printf("\n2) taxi (%2.f)\n", taxi_trip_price);

        while (*selected_form_of_transportation !=1 && *selected_form_of_transportation != 2)
        {
            printf("Enter your selection: ");
            if (scanf("%d", &*selected_form_of_transportation) != 1)
            {
                printf("Invalid selection. Choose 1 or 2.\n");
                while (getchar() != '\n');
            }
        }
        
        if (*selected_form_of_transportation == 1 && money_amount >= bus_ticket_price)
        {
            printf("You chose bus");
            money_amount -= bus_ticket_price;
        }
        else if (*selected_form_of_transportation == 1)
        {
            printf("You dont have enough money for bus");
        }

        if (*selected_form_of_transportation == 2 && money_amount >= taxi_trip_price)
        {
            printf("You chose taxi");
            money_amount -= taxi_trip_price;
        }
        else if (*selected_form_of_transportation == 2)
        {
            printf("You dont have enough money for taxi");
        }

        free(selected_form_of_transportation);
    }

    printf("\nYou need to walk...\n");

    return 0;
}
