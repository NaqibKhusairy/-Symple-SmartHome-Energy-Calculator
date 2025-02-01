//CB24019 - PUTERA NAQIB KHUSAIRI BIN ASRI
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Name[250] , Address [250] , MobileNo [250];
    int power_rating , hours_used , number_of_day;
    float energy_per_day , Total_Cumulative_Energy = 0 , Hours_Used_Rate;;

    printf("Name: ");
    gets(&Name);
    printf("Address: ");
    gets(&Address);
    printf("Mobile No: ");
    gets(&MobileNo);

    do
    {
        printf("\nEnter power rating for appliance (W): ");
        scanf("%d",&power_rating);
        printf("Enter number of hours used per day: ");
        scanf("%d", &hours_used);
        printf("Enter number of days: ");
        scanf("%d", &number_of_day);

        if(power_rating > 100 && power_rating < 3000)
        {
            if(power_rating < 500)
            {
                Hours_Used_Rate = 1.5;
            }
            else if(power_rating >= 500 && power_rating <= 1500)
            {
                Hours_Used_Rate = 3.0;
            }
            else if(power_rating > 1500)
            {
                Hours_Used_Rate = 5.0;
            }
            energy_per_day = Hours_Used_Rate * hours_used;
            for(int num = 1; num <= number_of_day; num++)
            {
                Total_Cumulative_Energy = Total_Cumulative_Energy + energy_per_day;
            }
            printf("\nTotal Energy Consumption: %.1f kWh\n", number_of_day , Total_Cumulative_Energy);
        }
        else
        {
            printf("Please Insert power rating between 100 and 3000 only\n");
            system("pause");
            system("cls");
            printf("Name: %s\n",Name);
            printf("Address: %s\n",Address);
            printf("Mobile No: %s\n",MobileNo);
        }
    }
    while(energy_per_day == 0.00);
    printf("Thank you\n");
    return 0;
}
