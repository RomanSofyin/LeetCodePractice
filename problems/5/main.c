#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* longestPalindrome(char*);

#define TEST_RUN_buf_len 256
#define TEST_RUN(str, res) \
{ \
    char __buff[TEST_RUN_buf_len]; \
    memset(__buff, 0, TEST_RUN_buf_len); \
    char * __s; \
    if ( strcmp( (__s = longestPalindrome(str)), (res) ) != 0 ) \
        printf( "test failed: expected=%s, returned=%s\n", (res), __s ); \
}

int main () {

    TEST_RUN("", "");
    TEST_RUN("a", "a");
    TEST_RUN("ab", "a");        // what about "b" ?
    TEST_RUN("aba", "aba");
    TEST_RUN("abab", "aba");    // "bab" is also fine
    
    return 0;
}

char * longestPalindrome(char * s){
    return "";
}
