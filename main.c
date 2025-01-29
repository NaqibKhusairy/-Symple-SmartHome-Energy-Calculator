//CB24019 - PUTERA NAQIB KHUSAIRI BIN ASRI
#include <stdio.h>
#include <string.h>

void print(int NumbeR_Of_DaY ,float EnerY_PeR_DaY ,float TotaL_CumulativE_EnergY)
{
    for(int NuM = 1; NuM <= NumbeR_Of_DaY ; NuM++)
    {
        printf("\nEnergy consumption for day %d: %.1f kWh", NuM , EnerY_PeR_DaY);
    }
    printf("\nTotal cumulative energy consumption for %d days: %.1f kWh\n", NumbeR_Of_DaY , TotaL_CumulativE_EnergY);
}

void calculate(int POWER_RATING ,int HOURS_USED ,int  NUMBER_OF_DAY ,float *ENERGY_PER_DAY)
{
    float TOTAL_CUMULATIVE_ENERGY = 0 , HOURS_USED_RATE;
    if(POWER_RATING < 500)
    {
        HOURS_USED_RATE = 1.5;
    }
    else if(POWER_RATING >= 500 && POWER_RATING <= 1500)
    {
        HOURS_USED_RATE = 3.0;
    }
    else if(POWER_RATING > 1500)
    {
        HOURS_USED_RATE = 5.0;
    }
    *ENERGY_PER_DAY = HOURS_USED_RATE * HOURS_USED;
    for(int num = 1; num <= NUMBER_OF_DAY; num++)
    {
        TOTAL_CUMULATIVE_ENERGY = TOTAL_CUMULATIVE_ENERGY + *ENERGY_PER_DAY;
    }
    print(NUMBER_OF_DAY , *ENERGY_PER_DAY , TOTAL_CUMULATIVE_ENERGY);
}

void read(int power_rating ,int  hours_used ,int  number_of_day ,float *energy_per_day , char name[250] , char address [250] , char mobile_no [250])
{
    if(power_rating > 100 && power_rating < 3000)
    {
        calculate(power_rating , hours_used , number_of_day , energy_per_day);
    }
    else
    {
        printf("Please Insert power rating between 100 and 3000 only\n");
        system("pause");
        system("cls");
        printf("Name: %s\n",name);
        printf("Address: %s\n",address);
        printf("Mobile No: %s\n",mobile_no);
    }
}

int main()
{
    char Name[250] , Address [250] , MobileNo [250];
    int PowerRating , HoursUsed , NumberOfDay;
    float EnergyPerDay;

    printf("Name: ");
    gets(&Name);
    printf("Address: ");
    gets(&Address);
    printf("Mobile No: ");
    gets(&MobileNo);

    do
    {
        printf("\nEnter power rating for appliance (W): ");
        scanf("%d",&PowerRating);
        printf("Enter number of hours used per day: ");
        scanf("%d", &HoursUsed);
        printf("Enter number of days: ");
        scanf("%d", &NumberOfDay);
        read(PowerRating , HoursUsed , NumberOfDay , &EnergyPerDay , Name , Address , MobileNo);
    }
    while(EnergyPerDay == 0.00);
    printf("Thank you\n");
    return 0;
}
