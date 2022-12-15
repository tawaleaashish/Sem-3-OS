#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,i,j;
    int x=0,y=0;
    scanf("%d", &n);
    int box[2*n-1][2*n-1];
    while(x<n)
    {
        for(i=x;i<2*n-1;i++)
        {
            for(j=y;j<2*n-1;j++)
            {
                if(i==x || i==2*n-x-1 )
                {
                    box[i][j]=n-x;
                }
                else if(j==y || j==2*n-y-1)
                {
                    box[i][j]=n-y;
                }
            }
        } 
        x++;
        y++;
    }
    for(i=0;i<2*n-1;i++)
    {
        for(j=0;j<2*n-1;j++)
        {
            printf("%d ",box[i][j]);
        }
        printf("\n");
    }
    
  	// Complete the code to print the pattern.
    return 0;
}