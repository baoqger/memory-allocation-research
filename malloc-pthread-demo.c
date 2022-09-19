#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>


void print_map() {
    char sz_exec_cmd[64];
    sprintf(sz_exec_cmd, "cat /proc/%d/maps", getpid());
    register void *rbp asm("rbp");
    register void *rsp asm("rsp");
    printf("Stack frame is %p-%p\n", rsp, rbp);
    printf("Output of /proc/%d/maps:\n", getpid());
    system(sz_exec_cmd);
    printf("\n");
    return;
}

void* runnable_func(void* arg) {
    printf("In child thread: before malloc\n");
    print_map();
    void *addr = malloc(1024);
    printf("In child thread: after malloc returned %p\n", addr);
    print_map();
    free(addr);
    return 0;
}

int main() {
    pthread_t th;
    void* s;
    printf("Process started with pid %d\n", getpid());
    void *addr = malloc(1024);
    printf("In parent thread: after malloc returned %p\n", addr);
    print_map();
    pthread_create(&th, NULL, &runnable_func, NULL);
    pthread_join(th, &s);
    free(addr);
    return 0;
    
}
