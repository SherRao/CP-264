#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include "main.h"

int ifib(int n) {
	int prev = 0, curr = 0, next = 1, i;
    for (i = 1; i < n; i++) {
		prev = curr;
		curr = next;
        if(curr > 0 && curr > INT_MAX - prev) 
            return -1;

        if(curr < 0 && curr < INT_MAX - prev)
            return -1;

		next = prev + curr;

	}  
    
    return next;
}

float median(float a[], int n) {
    

}

int main() {
    printf("\n===========================================================");
    printf("\n===========================================================");
    int n = ifib(10*100000*100000*100);
    printf("%d", n);

}