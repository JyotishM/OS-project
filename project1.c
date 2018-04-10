#include <stdio.h>
#include <stdlib.h>

#define min_pid 100
#define max_pid 1000
#define a CHAR_BIT

int size = max_pid - min_pid + 1;

unsigned char *b;

int allocate_map();
int allocate_pid();
void release_pid(int pid);

int allocate_map()
 {
    b = (unsigned char*)malloc((size+a-1)/a * sizeof(char));
    if (b) return 1;
    return -1;
}


int allocate_pid() 
{
    int i = 0;
    int pid = b[i/a] & (1 << (i & (a-1)));
    while (pid != 0) 
    {
        i++;
        pid = b[i/a] & (1 << (i & (a-1)));
    }

    if (i+min_pid > max_pid) return -1;
    b[i/a] |= 1 << (i & (a-1));
    return i+min_pid;
}

