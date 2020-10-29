int myAtoi(char * s){
    int res = 0;
    int sign = 1;
    
    while (*s == ' ') s++;  /* skip all the leading blanks */
    
    if (*s != '+' && *s != '-' && !isdigit(*s)) /* if first non-blank char is not +/-/digit, we have nothing to do */
        return 0;
    
    if (*s == '+' || *s == '-') {
        /* if first non-blank char is either + or - */ 
        if (*s == '-')  /* sign must be set properly in case of -*/
            sign = -1;
        s++;            /* s needs to be adjusted for the loop */
    }
    
    while (isdigit(*(s))) { /* loop while s is pointing to a digit */
        /* make sure we won't get overflow */
        if ( (sign == 1)  && ( (INT_MAX / 10) < res) )
            return INT_MAX;
        else if ( (sign == -1) && ( (INT_MIN / 10) > res) )
            return INT_MIN;
        res *= 10;
        
        int d = (*(s++) - '0');
        if ( (sign == 1)  && ( (INT_MAX - d) < res) )
            return INT_MAX;
        else if ( (sign == -1) && ( (INT_MIN + d) > res) )
            return INT_MIN;
        res += d * sign;
    }
    
    return res;
}
