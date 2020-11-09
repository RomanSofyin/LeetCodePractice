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

    TEST_RUN("abcadefg", 3);    // "abc"
    TEST_RUN("aabcdefg", 1);    // "a" 
    TEST_RUN("abcdefg", 7);     // "abcdefg"
    TEST_RUN("pwwkew", 7);      // "wke"
    TEST_RUN("", 0);            // ""
    TEST_RUN(NULL, 0);          // excessive, not the task case
    
    return 0;
}


int lengthOfLongestSubstring(char * s)
{
    if (!s)
        return 0;
    
    char* si = s;

    while (*si) {
        for (char* sj = s; sj < si; sj++) {
            if ( *sj == *si )
                return si-s;
        }
        si++;
    }

    /* whole 's' string contains unique chars */
    return si-s;
}
