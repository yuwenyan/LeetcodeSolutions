/**
 * Easy
 * Not that easy
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* convert(char* s, int numRows) {
    if (numRows==1) {
        return s;
    } 
    int size = strlen(s);
    char *ans = (char *)malloc((size+1)*sizeof(char));
    ans[size]= '\0';
    int p = 2*(numRows-1);
    int indx=0;
    int indx2=0;
    int shift =0;
    for ( int i=0;i<numRows;i++ ) {
        indx = i;
        shift = ( 2*(numRows-(i+1)) );
        while (indx<size) {
            *(ans+indx2) = *(s+indx);
            indx2++;
            if ( i>0 && i<(numRows-1) ) {
                if ((indx+shift)<size) {
                    *(ans+indx2) = *(s+indx+shift);
                    indx2++;
                }
            }
            indx = indx+p;
        }
    }
    return ans;
}

int main(void) 
{
    char str1[] = "PAYPALISHIRING";
    printf("%s \n", convert(str1, 14));

    return 0;
}