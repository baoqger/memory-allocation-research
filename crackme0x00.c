#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char password[] = "250382";

int main(int argc, char *argv[]) {
    setreuid(geteuid(), geteuid());
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    char *buf = (char*)malloc(200); 
    char *secret = (char*)malloc(200);

    strcpy(secret, password);
    printf("IOLI Crackme Level 0x00\n");
    printf("Password:");

    scanf("%s", buf);

    if (!strcmp(buf, secret)) {
        printf("Password Ok :)\n");
    } else {
        printf("Invalid password! %s\n", buf);
    }
    free(buf);
    free(secret);
    return 0;
}
