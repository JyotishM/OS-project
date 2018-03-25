#include<unistd.h>
#include<stdio.h>
#define MIN PID 100
#define MAX PID 1000
void main()
{
pid_t p1, p2;
p1= fork();
if (p1>0)
{
printf("Parent Process\n");
printf("It's Id:%d\n", getpid());
printf("Its parent ID:%d\n", getppid());
}
else if(p1==0)
{
printf("Child Process\n");
printf("Its Id:%d\n", getpid());
printf("Its parent Id:%d\n", getppid());
}
}
