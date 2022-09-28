#include <stdio.h>
#include <string.h>

int main() 
{
    char password[]="3v1lp@ss";
    char input[25];
    int match;

    printf("Enter your password\n");
    scanf("%s", input);

    match=strcmp(input, password);
    if(match == 0) 
        printf("Correct Pass\n Secret: XXXXXX");
    else 
        printf("Wrong Password. Try Again.");
    //return 0;
}
