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

    char *buf = (char*)malloc(100); 
    char *secret = (char*)malloc(100);

    strcpy(secret, password);
    printf("IOLI Crackme Level 0x00\n");
    printf("Password:");

    scanf("%s", buf);

    if (!strcmp(buf, secret)) {
        printf("Password Ok :)\n");
    } else {
        printf("Invalid password! %s\n", buf);
    }
    return 0;
}
