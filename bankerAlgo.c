#include<stdio.h>
void main()
{
    int i,j,n,r;
    printf("Number of Process = ");
    scanf("%d",&n);
    printf("Number of types of Resources = ");
    scanf("%d",&r);
    int Resource_allocated[5][3]={ {0, 1, 0 }, { 2, 0, 0 },{ 3, 0, 2 },{ 2, 1, 1 },{ 0, 0, 2 } },
    Resource_Max[5][3]={ { 7, 5, 3 },{ 3, 2, 2 },{ 9, 0, 2 },{ 2, 2, 2 },{ 4, 3, 3 } },
    total_resources[3]={10,5,7},allocated_total[3]={0,0,0},Resource_available[r],
    Resource_needed[n][r],f[n],flag,remaining=n,completed=0;
    for(i=0;i<n;i++)
    {
        f[i]=0;
        for(j=0;j<r;j++)
        {
            Resource_needed[i][j]=Resource_Max[i][j]-Resource_allocated[i][j];
            allocated_total[j] += Resource_allocated[i][j];
        }
    }
    for (j = 0; j < r; j++)
    {
        Resource_available[j] = total_resources[j] - allocated_total[j];
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        if(f[i]==0)
        {
            for(j=0;j<r;j++)
            {
                if(Resource_needed[i][j]>Resource_available[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(j=0;j<r;j++)
                {
                    Resource_available[j]+=Resource_allocated[i][j];
                }
                f[i]=1;
                remaining--;
                completed++;
                if(remaining>0)
                printf("P%d -> ",i);
                else
                printf("P%d\n",i);
            }
        }
        if(remaining>0 && i==n-1)
        i=-1;
        if(completed==n)
        break;
    }
}