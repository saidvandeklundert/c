/*
 In C, a string is an array of char data, terminated by the `/0` character.
*/
#include <stdio.h>

int main() {
    char *greeting = "Hello";

    char greeting_a[6] = {'H','e','l','l','o','\0'};
    char greeting_b[] = "Hello";
    char* greeting_c = "Hello";    
    
    
    
    printf("%s\n", greeting);
    printf("%s\n", greeting_a);
    printf("%s\n", greeting_b);
    printf("%s\n", greeting_c);
    return 0;
}