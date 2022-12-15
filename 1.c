#include<stdio.h>
void main()
{
    int n,i,j,y,tq,total_time=0,time=0,k,x,z;
    float avg_tat=0,avg_wt=0;
    printf("Number of Process = ");
    scanf("%d",&n);
    k=n;
    int at[2*n],bt[2*n],et[2*n],wt[2*n],tat[2*n],temp1[2*n],temp2[2*n],a[2*n];
    for(i=0;i<n;i++)
    {
        a[i]=i;
        printf("\nArrival time of process %d = ",i+1);
        scanf("%d",&at[i]);
        temp1[i]=at[i];
        printf("Burst time of process %d = ",i+1);
        scanf("%d",&bt[i]);
        temp2[i]=bt[i];
        total_time+=bt[i];
    }
    printf("\nTime Quantum = ");
    scanf("%d",&tq);
    while(total_time>0)
    {
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && bt[i]<=tq)
            {
                time+=bt[i];
                total_time-=bt[i];
                x=a[i];
                et[x]=time;
                bt[i]=0;
            }
            else if(at[i]<=time && bt[i]>tq)
            {
                time+=tq;
                total_time-=tq;
                bt[i]-=tq;
                z=i;
               for(y=0;y<n;y++)
               {
                if(at[y]>time)
                {
                    x=y;
                    for(j=n;j>n-x+1;j--)
                    {
                        at[j]=at[j-1];
                        a[j]=a[j-1];
                        bt[j]=bt[j-1];
                    }
                    at[x]=at[z];
                    a[x]=a[z];
                    bt[x]=bt[z];
                    n++;
                    break;
                }
                else if(y==n-1)
                {
                    at[y+1]=at[z];
                    a[y+1]=a[z];
                    bt[y+1]=bt[z];
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
        tat[j] = et[j] - temp1[j];
        wt[j] = et[j] - temp1[j]- temp2[j];
        printf("   %d\t\t %d\t\t %d\t\t%d\t\t%d\n",j+1,temp1[j],temp2[j],tat[j],wt[j]);
    }
    for(j=0;j<k;j++)
    {
        avg_tat+=tat[j];
        avg_wt+=wt[j];
    }
    printf("\nAverage Turn-Around Time = %0.2f",avg_tat/k);
    printf("\nAverage Waiting Time = %0.2f",avg_wt/k);

}