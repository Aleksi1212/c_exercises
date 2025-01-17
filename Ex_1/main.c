#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

int main(void) 
{
    float bus_ticket_price = validate_float_input("Enter price of bus ticket: ");
    float taxi_trip_price = validate_float_input("Enter price of taxi: ");
    float money_amount = validate_float_input("How much money you have: ");

    while (money_amount >= bus_ticket_price || money_amount >= taxi_trip_price)
    {
        int* selected_form_of_transportation = (int*)malloc(sizeof(int));

        printf("\nYou have %.2f money left", money_amount);
        printf("\nDo you wan to take");
        printf("\n1) bus (%.2f)", bus_ticket_price);
        printf("\n2) taxi (%.2f)\n", taxi_trip_price);

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
            printf("You chose bus\n");
            money_amount -= bus_ticket_price;
        }
        else if (*selected_form_of_transportation == 1)
        {
            printf("You dont have enough money for bus\n");
        }

        if (*selected_form_of_transportation == 2 && money_amount >= taxi_trip_price)
        {
            printf("You chose taxi\n");
            money_amount -= taxi_trip_price;
        }
        else if (*selected_form_of_transportation == 2)
        {
            printf("You dont have enough money for taxi\n");
        }

        free(selected_form_of_transportation);
    }

    printf("\nYou need to walk...\n");

    return 0;
}
