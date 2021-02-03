#include <stdio.h>

int str_length(char *s) {
    int length = 0;
    while(*s != 0) {
        length += 1;
        s++;

    }

    return length;    
}

int word_count(char *s) {
    int length = 0;
    while(*s != '\0') {
        char c = *s;
        char cn = *(s+1);
        if(c == ' ' && (cn != ' ' && cn != '\0'))
            length += 1;
        
        s++;
    }

    return length;
}

void lower_case(char *s) {
    while(*s != 0) {
        char c = *s;
        if(c >= 'A' && c <= 'Z')
            *s = *s + 32; 
        
        else *s = *s;
        s++;
    }
}

void trim(char *s) {
    int i, x;
    for(i = x = 0; s[i]; ++i)
        if(s[i] != ' ' || (i > 0 && s[i-1] != ' '))
            s[x++] = s[i];

    s[x - 1] = '\0';
}


int main() {
    char word[] = "     This Is    a Test   ";
    char *p = word;
    printf("Length: %d\n", str_length(p));
    printf("Word Count: %d\n", word_count(p));

    lower_case(p);
    printf("Lowercase: %s\n", p);

    trim(p);
    printf("Trim: %s|||\n", p);
    return 0;
}