/**
 * Easy
 *
 */

 #include <stdio.h>
 #include <stdlib.h>

 char* longestCommonPrefix(char** strs, int strsSize) {
    if ( strsSize==0 ) return "";
    if ( strsSize==1 ) return strs[0];
    int length=0;
    int j = 0;
    while ( 1 ) {
        for (int i=1;i<strsSize;++i ) {
            if ( *(*(strs+i)+j) != *((*strs)+j) ) {
                if (j==0) {
                    return "";
                } else {
                    length = j;
                }
            }
        }
        if ( *(*(strs)+j)=='\0' ) length =j;
        if (length !=0 ) break;
        j++;
    }
    char *ans =(char *) calloc((length+1),sizeof(char));
    *(ans+length) = '\0';
    for ( int i=0;i<length;++i ) {
        *(ans+i) = *((*strs)+i);
    }
    return ans;
}

int main(void) {
    char *test[2]={"c", "c"};
    printf("%s\n", longestCommonPrefix(test, 2) );

    return 0;
}