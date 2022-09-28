#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>


#define FLAGSIZE_MAX 64

char flag[FLAGSIZE_MAX];

struct data_t {
    char name[64];
};

struct fp_t {
    int (*fp)();
};

void winner() {
    printf("Heap overflow successful!\n");
}

int nowinner() {
    printf("level has been passed\n");
    return 0;
}

int main(int argc, char **argv) {
    struct data_t *d;
    struct fp_t *f;

    d = malloc(sizeof(struct data_t));
    f = malloc(sizeof(struct fp_t));

    f->fp = nowinner;
    printf("data is at %p, fp is at %p\n", d, f);
    strcpy(d->name, argv[1]);

    f->fp();
}
