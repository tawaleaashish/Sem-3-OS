#include<stdio.h>
void main()
{
    int n,i,j,y,tq,time=0,k,x,z,l;
    float avg_tat=0,avg_wt=0;
    printf("Number of Process = ");
    scanf("%d",&n);
    k=n;
    int at[2*n],bt[n],et[n],wt[n],tat[n],temp1[n],temp2[n],count=n,PID[n],queue[2*n];
    for(i=0;i<n;i++)
    {
        PID[i]=i;
        queue[i]=i;
        printf("\nArrival time of process %d = ",i+1);
        scanf("%d",&at[i]);
        temp1[i]=at[i];


        printf("Burst time of process %d = ",i+1);
        scanf("%d",&bt[i]);
        temp2[i]=bt[i];
    }
    printf("\nTime Quantum = ");
    scanf("%d",&tq);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(at[j]>at[j+1])
            {
                z=queue[j];
                queue[j]=queue[j+1];
                queue[j+1]=z;
                
                z=PID[j];
                PID[j]=PID[j+1];
                PID[j+1]=z;
                
                z=at[j];
                at[j]=at[j+1];
                at[j+1]=z;
            }
        }
    }
    while(count>0)
    {
        for(i=0;i<n;i++)
        {
            l=queue[i];
            if(temp1[l]<=time && bt[l]<=tq)
            {
                time+=bt[l];
                count--;
                et[l]=time;
                bt[l]=0;
            }
            else if(temp1[l]<=time && bt[l]>tq)
            {
                time+=tq;
                bt[l]-=tq;
               for(y=0;y<n;y++)
               {
                if(temp1[queue[y]]>time)
                {
                    x=y;
                    for(j=n;j>x;j--)
                    {
                        queue[j]=queue[j-1];
                    }
                    queue[x]=l;
                    n++;
                    break;
                }
                else if(y==n-1)
                {
                    queue[y+1]=l;
                    n++;
                    break;
                }
                
               }
            }
        }
    }
    printf("\nProcess No.  Arrival Time  Burst Time  Turn-around Time  Waiting Time\n");
    for (j=0; j<k; j++)
    {
        tat[PID[j]] = et[PID[j]] - at[j];
        wt[PID[j]] = et[PID[j]] - at[j]- temp2[PID[j]];
    }
    for(j=0;j<k;j++)
    {
        printf("   %d\t\t %d\t\t %d\t\t%d\t\t%d\n",j+1,temp1[j],temp2[j],tat[j],wt[j]);
        avg_tat+=tat[j];
        avg_wt+=wt[j];
    }
    printf("\nAverage Turn-Around Time = %0.2f",avg_tat/k);
    printf("\nAverage Waiting Time = %0.2f",avg_wt/k);

}