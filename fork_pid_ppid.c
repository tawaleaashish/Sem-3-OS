#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int pid;
    pid=fork();
    if(pid==-1)
    {
        printf("fork failed");
        exit (0);
    }
    if(pid==0)
    {
        printf("\nChild process is under execution");
        printf("\nProcess Id of the child process is %d ",getpid());
        printf("\nProcess Id of the parent process is %d ",getppid());
        printf("\n");
    }
    else
    {
        printf("\nParent process is under execution");
        printf("\nProcess Id of the parent process is %d ",getpid());
        printf("\nProcess Id of the child process in parent is %d ",pid);
        printf("\nProcess Id of the parent process of parent is %d ",getppid());
        printf("\n");
    }
    return(0);
}