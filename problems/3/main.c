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

    TEST_RUN("", 0);            // ""
    TEST_RUN("a", 1);           // "a" 
    TEST_RUN("aa", 1);          // "a" 
    TEST_RUN("abc", 3);         // "a" 
    TEST_RUN("abca", 3);        // "abc"
    TEST_RUN("abcad", 4);       // "bcad"
    TEST_RUN("abcadb", 4);      // "bcad"
    /* * */
    TEST_RUN("abcabcbb", 3);    // "abc"
    TEST_RUN("abbb", 2);        // "ab"
    TEST_RUN(NULL, 0);          // excessive, not the task case
    
    return 0;
}


int lengthOfLongestSubstring(char * s)
{
    if (!s || !(*s))    // NULL or ""
        return 0;
    
    int res = 1;        // minumum one char string

    char* si = s;       //  right boundary of the string

    while ( *(++si) ) { // loop throug all the chars in string
        for (char* sn = s; sn < si; sn++ ) {            // check if all the chars in substr [s;si] are uniqueue
            if ( *sn == *si ) {                         // a duplicate is found
                res = ( res < (si-s) ) ? (si-s) : res;  // update length if needed
                s = sn + 1;                             // updateleft substr boundary
                break;                                  // proceed with new substr [s;(si+1)]
            }
        }
    }
    res = ( res < (si-s) ) ? (si-s) : res;  // in case were no dupl in last substr
    
    return res;
}
