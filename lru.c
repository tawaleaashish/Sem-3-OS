#include<stdio.h>
void main()
{
    int frame,i,j,x,n,page_count=0,k,z,l;
    printf("Number of frames = ");
    scanf("%d",&frame);
    int block[frame],count[frame];
    for(i=0;i<frame;i++)
    {
        block[i]=-1000;
        count[i]=0;
    }
    printf("Enter size of reference string: ");
    scanf("%d",&n);
    int ref_string[n],Max=-1000,Min=1000;
    printf("Enter the reference string : \n");
    for (j=0;j<n;j++)
    {
        printf("Element %d = ",j+1);
        scanf("%d",&ref_string[j]);
    }
    for(j=0;j<n;j++)
    {
        for(i=0;i<frame;i++)
        {
            if(block[i]==ref_string[j])
            {
                count[i]=0;
                break;
            }
            else if(block[i]!=ref_string[j] && i==frame-1)
            {
                if(block[frame-1]!=-1000)
                {
                    for(l=0;l<frame;l++)
                    {
                        if(count[l]>Max)
                        {
                            z=l;
                            Max=count[l]; 
                        }
                    }
                    block[z]=ref_string[j];
                    count[z]=0;
                    page_count++;
                    Max=-1000;
                }
                else if(block[frame-1]==-1000)
                {
                    for(l=0;l<frame;l++)
                    {
                        if(count[l]<Min)
                        {
                            z=l;
                            Min=count[l]; 
                        }
                    }
                    block[z]=ref_string[j];
                    count[z]=0;
                    page_count++;
                    Min=1000;
                }
            }
        }
        for(k=0;k<frame;k++)
        {
            if(block[k]!=-1000)
            {
               count[k]++;
            }
        }
    }
    printf("\nPage fault = %d\n",page_count);
}