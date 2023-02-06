#include<stdio.h>
void main()
{
    int n,i,j,t,totalTime=0;
    float avg_TAT=0,avg_WT=0;
    printf("Number of processes = ");
    scanf("%d",&n);
    int arrivalTime[n],BurstTime[n],ExitTime[n],WaitingTime[n],TurnAroundTime[n],PID[n];
    for(i=0;i<n;i++)
    {
        printf("\n");
        PID[i]=i;
        printf("Arrival time of Process %d = ",i+1);
        scanf("%d",&arrivalTime[i]);
        printf("Burst time of Process %d = ",i+1);
        scanf("%d",&BurstTime[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arrivalTime[j]<arrivalTime[i])
            {
                t=arrivalTime[i];
                arrivalTime[i]=arrivalTime[j];
                arrivalTime[j]=t;

                t=BurstTime[i];
                BurstTime[i]=BurstTime[j];
                BurstTime[j]=t;

                t=PID[i];
                PID[i]=PID[j];
                PID[j]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        ExitTime[i]=totalTime+BurstTime[i];
        TurnAroundTime[i]=ExitTime[i]-arrivalTime[i];
        WaitingTime[i]=TurnAroundTime[i]-BurstTime[i];
        totalTime+=BurstTime[i];
        avg_TAT+=TurnAroundTime[i];
        avg_WT+=WaitingTime[i];
    }
    printf("\nProcess No.  Arrival time   Burst time   Turn around time   Waiting time\n");
    for(i=0;i<n;i++)
    {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n",i+1,arrivalTime[PID[i]],BurstTime[PID[i]],TurnAroundTime[PID[i]],WaitingTime[PID[i]]);
    }
    printf("Average Turn Around Time = %.2f\n",avg_TAT/n);
    printf("Average Waiting Time = %.2f\n",avg_WT/n);

}