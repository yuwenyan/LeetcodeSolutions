/**
 * Easy
 *
 * This is a stupid question.
 */
#include <stdio.h>
#include <stdint.h>

int myAtoi(char* str) {
    long int ans=0;
    if ( *str=='\0' ) return ans;
    int count = 0;
    int sign = 1;
    while(*(str+count)<'0' || *(str+count)>'9') {
        if (*(str+count)=='-') {
            sign = -sign;
        }
        if ( *(str+count)=='\0' ) {
            return 0;
        }
        count++;
    }
    while ( *(str+count)>='0' && *(str+count)<='9' ) {
        ans = ans*10+(*(str+count) - '0');
        if (ans>INT32_MAX) {
            return 0;
        }
        count++;
    }
    return (sign*ans);
}

int main(void) {
    char *str[3];
    str[0] = "  123 ";
    str[1] = "+123.4";
    str[2] = "-1234";

    for (int i = 0; i < 3; i++)
        printf("%d\n", myAtoi(str[i]));

    return 0;
}