#include<bits/stdc++.h>
using namespace std;

int process[50],aTime[50],bTime[50],abTime[50],wTime[50],tat_time[50];
int n = 0,i = 0 ;
float aw_time = 0, atat_time = 0;


void input()
{
    printf("\nEnter the number of process : ");


    scanf("%d",&n);

    printf("Enter the Arrival time and Burst time.\n\n");

    printf("\tAT BT\n");
    for(i = 0 ; i < n ; i++)
    {
        process[i]=i+1;
        printf("P%d :\t", i+1);
        scanf("%d\t%d",&aTime[i],&bTime[i]);
    }

}

void calculate()
{
    wTime[0] = 0;

    tat_time[0] = bTime[0];

    abTime[0] = bTime[0]+aTime[0];

    for( i = 1 ; i < n ; i++)
    {
        abTime[i] = abTime[i-1] + bTime[i];
        tat_time[i] = abTime[i] - aTime[i];
        wTime[i] = tat_time[i] - bTime[i];
    }

    for(i = 0 ; i < n ; i++)
    {
        aw_time = aw_time + wTime[i];
        atat_time = atat_time + tat_time[i];
    }

}


void display()
{
    printf("\tAT\tBT\tCT\tTaT\tWT\n");
    for(i = 0 ; i < n ; i++)
    {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n",i,aTime[i],bTime[i],abTime[i],tat_time[i],wTime[i]);
    }

    printf("\nAverage waiting time : %0.2f",aw_time/n);

    printf("\nAverage turn around time : %0.2f",atat_time/n);

}


int main()
{
       printf("FCFS CPU Scheduling Algorithm\n");
       input();
       calculate();
       display();
       return 0;

}
