/**
 * Easy
 * Determine whether an integer is a palindrome. Do this without extra space.
 */

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x<0) return false;

    int mask = 1;
    int left, right;
    while ( x/mask>=10 ) {
        mask = mask*10;
    }

    while (x>0) {
        right = x%10;
        left = x/mask;
        if ( right != left ) {
            return false;
        }
        x = x%mask;
        x=x/10;
        mask = mask/100;
    }
    return true;
}

int main(void) {
    int x = 1000021;
    printf("%s\n", isPalindrome(x)? "true":"false" );
    return 0;
}