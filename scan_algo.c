#include<stdio.h>
void main()
{
   int head_pos,a,seek_num=0,direction;
   int i,j,t,n=8;
   int req_seq[8]={98, 183, 41, 122, 14, 124, 65, 67},seek_seq[9];
   for(i=0;i<n-1;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if(req_seq[i]>req_seq[j])
           {
               t=req_seq[i];
               req_seq[i]=req_seq[j];
               req_seq[j]=t;
           }
       }
   }
   printf("Enter Initial Head Position: ");
   scanf("%d",&head_pos);
   printf("(Enter 0 for left and 1 for right)\n");
   printf("Enter direction: ");
   scanf("%d",&direction);
   if(direction==0)
   {
      for(i=0;i<n;i++)
      {
         if(req_seq[i]>=head_pos)
         {
           j=i-1;
           break;
         }
      }
      seek_num+=head_pos-req_seq[j];
      for(i=0;j>=0;i++)
      {
         seek_seq[i]=req_seq[j];
         j--;
         t=i;
      }
      seek_seq[t+1]=0;
      for(i=t+2;i<=n;i++)
      {
         seek_seq[i]=req_seq[i-1];
      }
      for(i=n;i>0;i--)
      {
         t=seek_seq[i]-seek_seq[i-1];
         if(t>=0)
         {
           seek_num+=t;
         }
         else if(t<0)
         {
            t=t*(-1);
            seek_num+=t;
         }
      }
      printf("Total number of seek operations = %d\n",seek_num);
      printf("Seek sequence:\n");
      for(i=0;i<=n;i++)
      {
       printf("%d\n",seek_seq[i]);
      }
   }
   else
   {
    printf("Maximun cylinder value =");
    scanf("%d",&t);
    for(i=0;i<n;i++)
    {
       if(req_seq[i]>=head_pos)
       {
         j=i;
         break;
       }
    }
    seek_num+=req_seq[j]-head_pos;
    for(i=0;i<n-j;i++)
    {
       seek_seq[i]=req_seq[i+j];
    }
    seek_seq[i]=t;
    for(i=n-j+1;i<=n;i++)
    {
       seek_seq[i]=req_seq[j-1];
       j--;
    }
    for(i=n;i>0;i--)
    {
       t=seek_seq[i]-seek_seq[i-1];
       if(t>=0)
       {
         seek_num+=t;
       }
       else if(t<0)
       {
          t=t*(-1);
          seek_num+=t;
       }
    }
    printf("Total number of seek operations = %d\n",seek_num);
    printf("Seek sequence:\n");
    for(i=0;i<=n;i++)
    {
     printf("%d\n",seek_seq[i]);
    }
   }
}