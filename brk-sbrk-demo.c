// sbrk and brk demo

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    void *curr_brk, *tmp_brk = NULL;

    printf("Welcome to sbark example:%d\n", getpid());
    getchar();
    
    // sbrk(0) gives current program break location
    tmp_brk = curr_brk = sbrk(0);
    printf("Program break Location:%p\n", curr_brk);
    getchar();

    // brk(addr) increments/decrements program break location
    brk(curr_brk + 4096);
    curr_brk = sbrk(0);
    printf("Program break Location:%p\n", curr_brk);
    getchar();

    brk(tmp_brk);
    curr_brk = sbrk(0);
    printf("Program break Location:%p\n", curr_brk);
    getchar();


    return 0;
}
