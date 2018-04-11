#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN_PID 100
#define MAX_PID 1000
#define a CHAR_BIT

int size = MAX_PID - MIN_PID + 1;

char *b;

int allocate_map();
int allocate_pid();
void release_pid(int pid);

int main() 
{
    int c = allocate_map();
    if (c == 1) {
        printf("Bitmap Data Structure starts working\n\n");
        int id = 0, i;


	for(i=0; i<5;i++)
        {
            int d = allocate_pid();
            printf("Process %d: pid = %d\n", i+1, d);
  
        }

//    release_pid(100); printf("\nProcess having pid 100 is released.");
  //  release_pid(101); printf("\nProcess having pid 101 is released.");
    //release_pid(102); printf("\nProcess having pid 102 is released.");
    //release_pid(103); printf("\nProcess having pid 103 is released.");
    //release_pid(104); printf("\nProcess having pid 104 is released.");


        int d = allocate_pid(); 
	printf("\n\nProcess %d : pid = %d\n", ++i, d);
    	d = allocate_pid(); 
	printf("Process %d : pid = %d\n", ++i, d);
	d = allocate_pid();
	printf("Process %d : pid = %d\n", ++i, d);
	d = allocate_pid();
	printf("Process %d : pid = %d\n", ++i, d);
	d = allocate_pid();
	printf("Process %d : pid = %d\n", ++i, d);
    }
    else printf("Bitmap Data Structure failed working\n");
}


int allocate_map() {
    b = (char*)malloc((size+a-1)/a * sizeof(char));
    if (b) return 1;
    return -1;
}


int allocate_pid() {
    int i = 0;
    int pid = b[i/a] & (1 << (i & (a-1)));
    while (pid != 0) {
        i++;
        pid = b[i/a] & (1 << (i & (a-1)));
        }

    if (i+MIN_PID > MAX_PID) return -1;
    b[i/a] |= 1 << (i & (a-1));
    return i+MIN_PID;
}


void release_pid(int pid) {
    if (pid < 100) {
        printf("\nInvalid PID: The range lies between 100 to 1000");
        return;
    }
    int i = pid - MIN_PID;
    b[i/a] &= ~(1 << (i & (a-1)));
}
