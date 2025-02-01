//CB24019 - PUTERA NAQIB KHUSAIRI BIN ASRI
#include <stdio.h>                                                                                  //Preprocessor directive for standard input/output
#include <stdlib.h>                                                                                 //Used for standard library functions like exit()

void print(float Total_Cumulative_Energy)                                                           //Declare print Module with parameter
{
    printf("\nTotal Energy Consumption: %.1f kWh\n", Total_Cumulative_Energy);                      //Print Output
}

void calculate(int power_rating ,int hours_used ,int  number_of_day ,float *energy_per_day)         //Declare calculate Module with parameter
{
    float Total_Cumulative_Energy = 0 , Hours_Used_Rate;                                            //Declare private variable for calculate Module
    if(power_rating < 500)                                                                          //IF power_rating less than 500 THEN
    {
        Hours_Used_Rate = 1.5;                                                                      //set Hours_Used_Rate to 1.5
    }
    else if(power_rating >= 500 && power_rating <= 1500)                                            //IF power_rating more & equal to 500 and power_rating less & equal to 1500 THEN
    {
        Hours_Used_Rate = 3.0;                                                                      //set Hours_Used_Rate to 3.0
    }
    else if(power_rating > 1500)                                                                    //IF power_rating more than 1500
    {
        Hours_Used_Rate = 5.0;                                                                      //set Hours_Used_Rate to 5.0
    }
    *energy_per_day = Hours_Used_Rate * hours_used;                                                 //calculate energy_per_day
    for(int num = 1; num <= number_of_day; num++)                                                   //Loop for num = 1 until num equal tu number_of_day
    {
        Total_Cumulative_Energy = Total_Cumulative_Energy + *energy_per_day;                        //calculate Total_Cumulative_Energy
    }
    print(Total_Cumulative_Energy);                                                                 //call print module and past the parameter value
}

int main()                                                                                          //Declare main module
{
    char Name[250] , Address [250] , MobileNo [250];                                                //Declare private variable for main Module
    int power_rating , hours_used , number_of_day;                                                  //Declare private variable for main Module
    float energy_per_day;                                                                           //Declare private variable for main Module

    printf("Name: ");                                                                               //display "Name: "
    gets(&Name);                                                                                    //input Name value
    printf("Address: ");                                                                            //display "Address: "
    gets(&Address);                                                                                 //input Name value
    printf("Mobile No: ");                                                                          //display "Mobile No: "
    gets(&MobileNo);                                                                                //input Name value

    do                                                                                              //loop the program
    {
        printf("\nEnter power rating for appliance (W): ");                                         //display "Enter power rating for appliance (W): "
        scanf("%d",&power_rating);                                                                  //input power_rating
        printf("Enter number of hours used per day: ");                                             //display "Enter number of hours used per day: "
        scanf("%d", &hours_used);                                                                   //input hours_used
        printf("Enter number of days: ");                                                           //display "Enter number of days "
        scanf("%d", &number_of_day);                                                                //input number_of_day

        if(power_rating > 100 && power_rating < 3000)                                               //IF power_rating more 100 and power_rating lest than 3000 THEN
        {
            calculate(power_rating , hours_used , number_of_day , &energy_per_day);                 //call calculate module and past the parameter value
        }
        else                                                                                        //else
        {
            printf("Please Insert power rating between 100 and 3000 only\n");                       //Print error output
            system("pause");                                                                        //Pause the system
            system("cls");                                                                          //clear screen
            printf("Name: %s\n",Name);                                                              //print Name
            printf("Address: %s\n",Address);                                                        //print Address
            printf("Mobile No: %s\n",MobileNo);                                                     //print MobileNo
        }
    }
    while(energy_per_day == 0.00);                                                                  //loop the system if energy_per_day == 0.00
    printf("Thank you\n");                                                                          //print thankyou
    return 0;                                                                                       //Indicate successful program termination
}
