int myAtoi(char * s){
    int res;
    bool pos = 1;
    printf("100: INT_MIN=%d, INT_MAX=%d \n", INT_MIN, INT_MAX);   
    
   s = "42"; // "   +123e34";
    
    while (*s == ' ')
        s++;
    
    if (*s != '+' && *s != '-' && !isdigit(*s))
        return 0;
    
    if (*s == '+')
        s++;
    else if (*s == '-') {
        pos = -1;
        s++;
    }
    
    char cz = '0';
    res = (*(s++) - cz) * pos;
    
    printf("400: res=%d \n", res);
    
    while (isdigit(*(s++))) {
        int acc = res * 10 + (*s - cz) * pos;
        if (pos == 1 && acc < res)
            return INT_MAX;
        if (pos == -1 && acc > res)
            return INT_MIN;
        res = acc;
    }
    
    return res;
}