#include<stdio.h>



//Using this function to get the first/starting day of the year

int getfirstdayoftheyear(int year)
{
    int day = (year*365 + ((year-1)/4)- ((year-1)/100) + ((year-1)/400))%7;
    return day;
}

int main()
{
    char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int daysinmont[]= {31, 28, 31,30,31,30,31,31,30,31,30,31};
    int i,j,totaldays,weekday,spacecounter=0,year;
    printf("Enter your year :\n");
    scanf("%d",&year);
    printf("\n\n**************** Welcome To %d *****************\n\n",year);

    //check if it's a leap year
    if((year % 4 == 0 && year % 100!=0) ||( year % 400==0))
    {
        daysinmont[1]=29;
    }

    //Getting the first day of the year by calling the function
    weekday=getfirstdayoftheyear(year);
    for(i=0; i<12; i++)
    {
        printf("\n\n\n-------------------------%s----------------------\n",months[i]);
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");

        for(spacecounter=1; spacecounter<=weekday; spacecounter++)
        {
            printf("      ");
        }
        totaldays=daysinmont[i];
        for(j=1; j<=totaldays; j++)
        {
            printf("%6d",j);
            weekday++;
            if(weekday>6)
            {
                weekday=0;
                printf("\n");
            }
        }
    }
    return 0;
}
