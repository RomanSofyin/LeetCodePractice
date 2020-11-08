#include <stdlib.h>
#include <stdio.h>

int lengthOfLongestSubstring(char*);

#define TEST_RUN(str, len) \
{ \
    char* __str = str ? str : "NULL"; \
    int __len = 0; \
    if ( ( (__len) = lengthOfLongestSubstring(str)) != (len) ) \
        printf( "test failed: str=%s, expected=%d, returned=%d\n", __str, (len), (__len) ); \
}

int main () {

    TEST_RUN("abcadefg", 3);
    TEST_RUN("", 0);
    TEST_RUN(NULL, 0);
    
    return 0;
}


int lengthOfLongestSubstring(char * s){

    return 0;
}
