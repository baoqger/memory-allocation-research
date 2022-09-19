#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void print_map() {
    char sz_exec_cmd[64];
    sprintf(sz_exec_cmd, "cat /proc/%d/maps", getpid());
    printf("Output of /proc/%d/maps:\n", getpid());
    system(sz_exec_cmd);
    printf("\n");
    return;
}

int main() {
    printf("Process started with pid %d\n", getpid());
    // Get current brk ptr with sbrk(0)
    printf("Before calling brk, end of heap is at %p\n", sbrk(0));
    

    // Increment brk ptr by 1 page size (4kb)
    brk(sbrk(0) + 4096);
    printf("After +4096, end of heap is at %p\n", sbrk(0));
    
    sbrk(-4096);
    printf("After -4096, end of heap is at %p\n", sbrk(0));


    print_map();

    void* p1 = malloc(120 * 1024);
    printf("Invoked malloc(120*1024) for the first time.\n");
    print_map();

    void* p2 = malloc(120* 1024);
    printf("Invoked malloc(120*1024) for the second time.\n");
    print_map();

    free(p1);
    free(p2);

    void *p3 = malloc(140*1024);
    printf("Invoked malloc(140*1024).\n");
    print_map();
    free(p3);

    return 0;
}
