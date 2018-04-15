#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define MAX_PID 1000
#define MIN_PID 100
int pid_map[];
int allocate_pid();
void release_pid(int pid);
int allocate_map();

int allocate_map()
{
for(int i=0; i<MAX_PID; i++)
{
pid_map[i]=0;
}
return 1;
}


int allocate_pid()
{
for(int j=0; j<MAX_PID;j++)
{
if(pid_map[j]==0)
{
pid_map[j]=1;
return j+MIN_PID;
}
}
return 1;
}

void relaese_pid(int pid)
{
pid_map[MIN_PID+pid]=0;
}

int main()
{
allocate_map();
int a= allocate_pid();
printf("Allocate PID:%d \n",a);
release_pid(a);
}
