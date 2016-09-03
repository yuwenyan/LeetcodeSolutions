/**
 * Easy
 * Reverse Integer
 */

#include <stdio.h>
#include <stdint.h>


int reverse(int x) {
    int sign=1;
    long int ans=0;
    if (x<0) {
        sign = -1;
        x = -x;
    }
    while (x>0) {
        ans = ans*10+x%10;
        x = x/10;
    }
    
    if ( ans>(INT32_MAX) ) {
        return 0;
    }
    
    if ( (ans*sign) > INT32_MAX ) {
        return 0;
    } 
    
    return sign*ans;
}

int main(void) {
    int x1 = 123;
    int x2 = -321;
    int x3 = 6824200209;
    int x4 = -98744323;
    printf("%d\n", reverse(x1));
    printf("%d\n", reverse(x2));
    printf("%d\n", reverse(x3));
    printf("%d\n", reverse(x4));
    return 0;
}