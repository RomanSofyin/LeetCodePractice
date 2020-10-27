int myAtoi(char * s){
    int res;
    int pos = 1;
    printf("100: INT_MIN=%d, INT_MAX=%d \n", INT_MIN, INT_MAX);   
    
    while (*s == ' ')
        s++;
    
    printf("350: *s=%c \n", *s);
    
    if (*s != '+' && *s != '-' && !isdigit(*s))
        return 0;
    
    if (*s == '+' || *s == '-') {
        if ( !isdigit(*(s+1)) )
            return 0;
        if (*s == '-')
            pos = -1;
        s++;
    }
    
    int int_max_div_10 = INT_MAX / 10;
    int int_min_div_10 = INT_MIN / 10;

    
    char cz = '0';
    res = (*s - cz) * pos;
    
    printf("400: res=%d, pos=%d \n", res, pos);
    
    int acc;
    
    while (isdigit(*(++s))) {
        if (pos == 1) {
            if ( int_max_div_10 >= res )
                acc = res * 10;
        } else {
            
        }
        acc = res * 10;
        
        printf("480: acc=%d, res=%d \n", acc, res);
        acc = acc + (*s - cz) * pos;
        printf("500: acc=%d, res=%d \n", acc, res);
        
        if (pos == 1 && acc < res)
            return INT_MAX;
        if (pos == -1 && acc > res)
            return INT_MIN;
        
        res = acc;
    }
    
    return res;
}
