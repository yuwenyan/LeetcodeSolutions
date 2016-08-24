/**
* Easy
* Write a function that takes a string as input and returns the string reversed.
* Example:
* Given s = "hello", return "olleh".
*/
#include <stdio.h>

char* reverseString(char* s) {
    char* head = s;
    char* tail = s;
    char temp;
    
    while (*tail != '\0') {
        tail++;
    }
    tail--;
    
    while (tail > head) {
        *tail ^= *head;
        *head ^= *tail;
        *tail ^= *head;
        tail--;
        head++;
    }
    
    return s;
}

char* reverseString2(char* s) {
    char* head = s;
    char* tail = s;
    char temp;
    
    while (*tail++) {};
    tail--;
    tail--;
    
    while (tail > head) {
        temp = *tail;
        *tail-- = *head;
        *head++ = temp;
    }
    
    return s;
}

int main(void)
{
    char *out;
    char testIn[] = "hello";
    char testOut[] = "olleh";

    out = reverseString(testIn);

    printf("Expect:\n");
    printf("%s \n", testOut);
    printf("Result: \n");
    printf("%s \n", out);

    return 0;
}