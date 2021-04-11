void int2str(int a, char *p) {
    while(a > 0) {
        int num = a % 10;
        *p = num + '0';

        p++;
        a /= 10;

    }
    
    *p = '\0';

}