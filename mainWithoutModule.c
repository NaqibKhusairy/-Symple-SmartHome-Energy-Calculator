//CB24019 - PUTERA NAQIB KHUSAIRI BIN ASRI
#include <stdio.h>
#include <string.h>
int main()
{
    char Name[250] , Address [250] , MobileNo [250];
    int PowerRating , HoursUsed , NumberOfDay;
    float EnergyPerDay , TotalCumlativeEnergy = 0 , HoursUsedRate;

    printf("Name: ");
    gets(&Name);
    printf("Address: ");
    gets(&Address);
    printf("Mobile Number: ");
    gets(&MobileNo);

    do
    {
        printf("\nEnter power rating for appliance (W): ");
        scanf("%d",&PowerRating);
        printf("Enter number of hours used per day: ");
        scanf("%d", &HoursUsed);
        printf("Enter number of days: ");
        scanf("%d", &NumberOfDay);
        if(PowerRating > 100 && PowerRating < 3000)
        {
            if(PowerRating < 500)
            {
                HoursUsedRate = 1.5;
            }
            else if(PowerRating >= 500 && PowerRating <=1500)
            {
                HoursUsedRate = 3.0;
            }
            else if(PowerRating > 1500)
            {
                HoursUsedRate = 5.0;
            }
            EnergyPerDay = HoursUsedRate * HoursUsed;
            for(int num  = 1; num <= NumberOfDay; num++)
            {
                TotalCumlativeEnergy = TotalCumlativeEnergy + EnergyPerDay;
            }
            printf("\nTotal Energy Consumption: %.1f kWh\n", TotalCumlativeEnergy);
        }
        else
        {
            printf("Please Insert power rating between 100 and 300 only\n");
            system("pause");
            system("cls");
            printf("Name: %s\n",Name);
            printf("Address: %s\n",Address);
            printf("Mobile Number: %s\n",MobileNo);
        }
    }
    while(EnergyPerDay == 0.00);
    printf("Thank You\n");
    return 0;
}
