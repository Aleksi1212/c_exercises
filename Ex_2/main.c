#include <stdio.h>
#include "../utils.h"

int main(void)
{
    const int INCOME_ARRAY_SIZE = 12;

    float income[INCOME_ARRAY_SIZE];

    float tax_rate = validate_float_input("Enter tax rate: ");
    float income_limit = validate_float_input("Enter income limit: "); 
    float tax_rate_over_income_limit = validate_float_input("Enter tax rate for income over the limit: ");

    for (int i = 0; i < INCOME_ARRAY_SIZE; i++)
    {
        char message[30];
        sprintf(message, "Enter income for month %d: ", i+1);

        income[i] = validate_float_input(message);
    }

    float yearly_income = 0;

    printf("%-12s%-12s %s\n", "month", "income", "tax");
    for (int i = 0; i < INCOME_ARRAY_SIZE; i++)
    {
        yearly_income += income[i];
        float tax = yearly_income > income_limit
            ? income[i] * (tax_rate_over_income_limit / 100)
            : income[i] * (tax_rate / 100);

        printf("%5d %12.2f %9.2f\n", i+1, income[i], tax);
    }
    
    return 0;
}