/*
     12321      -> TRUE
    -12321      -> FALSE
     3212       -> FALSE
     32123      -> TRUE
*/

#define MAX_NUM_LEN 12  // -2^31 (i.e. -2,147,483,648)   <=   x   <=   2^31 - 1 (i.e. 2,147,483,647)

bool isPalindrome(int x){
    char str[MAX_NUM_LEN];
    int len = sprintf (&str[0], "%d", x);   // or just 'str'
    
    for (int i = 0, j = (len-1); i < j; i++, j--) {
        if (str[i] != str[j])
            return false;
    }
    
    return true;
}