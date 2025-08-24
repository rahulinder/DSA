#include <stdio.h>
#include <string.h> 

int main() {
    char str1[] = "hello my "; 
    char str2[] = "World!";    

    printf("Original String 1: %s\n", str1);
    printf("Original String 2: %s\n", str2);

   
    strcat(str1, str2);

    printf("Concatenated String: %s\n", str1);

    return 0;
}
