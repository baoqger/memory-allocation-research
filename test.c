#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *q;
    char *p;
    int x;
    char input[3];

    while(1) {
        read(0, input,3);
        x = atoi(input);
        q = (char*)malloc(x);

        read(0, input, 3);
        x = atoi(input);
        p = (char*)malloc(x);

        free(q);
        free(p);
    }   
    return 0;
}
