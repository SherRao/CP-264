/*
 -------------------------------------
 File:    bigint.c
 Project: raox6250_a05

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-02-25
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bigint.h"

BIGINT bigint(char *p) {
    BIGINT bn = {0};
    if(p == NULL) 
        return bn;
    
    else if( !(*p >= '0' && *p <= '9') ) // not begin with digits 
        return bn;

    else if(*p == '0' && *(p+1) == '\0') { // just "0"
        insert_end(&bn.start, &bn.end, new_node(*p -'0'));
        return bn;
  
    } else { 
        while(*p) {
          if(*p >= '0' && *p <= '9')
              insert_end(&bn.start, &bn.end, new_node(*p -'0'));
        
          else {
            clean_bigint(&bn);   
            break;
          }
      
          p++;
        }
    
      return bn;
    }
}

void display_bigint(BIGINT bignumber) {
    NODE *ptr = bignumber.start;
    while(ptr != NULL) {
        printf("%d", ptr->data);
        ptr = ptr->next;
  
    }
}

void clean_bigint(BIGINT *bignumberp) {
    clean(&bignumberp->start, &bignumberp->end);

}

BIGINT addnew(BIGINT op1, BIGINT op2) {
	BIGINT sum = bigint(NULL);

	//as long as those numbers exist to use
	if (op1.start != NULL && op2.start != NULL) {

		int small_sum = 0; //this gets re-written every iteration through the loop
		int carry_value = 0; //carry value during simple addition, if >=10 then carry_value = 1

		NODE *num1 = op1.end;
		NODE *num2 = op2.end;

		//run as long as one number isnt finished its addition
		while (num1 != NULL || num2 != NULL) {

			small_sum = carry_value + (num1 != NULL ? num1->data : 0) + (num2 != NULL ? num2->data : 0);

			carry_value = small_sum;
			//account for the carry value, leave the remainder
			if (carry_value >= 10) {
				carry_value = 1;
				small_sum = small_sum - 10;
			} else {
				carry_value = 0;
			}

			//add the small_sum value to the start of the sum bigint list
			insert_start(&sum.start, &sum.end, new_node(small_sum));

			//we are moving from right to left, like we would in binary addition
			if (num1 != NULL)
				num1 = num1->prev;
			if (num2 != NULL)
				num2 = num2->prev;

		}

		//carry_value at the end might get forgotten, here, we dont leave homies behind
		if (carry_value > 0)
			insert_start(&sum.start, &sum.end, new_node(carry_value));

	}

	//we want the sum 10000000000000000000
	return sum;

}

BIGINT add(BIGINT op1, BIGINT op2) {
    BIGINT result = bigint(NULL);
    if(op1.start != NULL && op2.start != NULL) { 
        NODE *a = op1.end;
        NODE *b = op2.end;  
        int carry = 0;
        int sum = 0;

        while(a != NULL || b != NULL) {
            int n = (a == NULL) ? 0 : a->data;
            int m = (b == NULL) ? 0 : b->data;
            sum = carry + n + m;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;

            } else
                carry = 0;
        
            insert_start(&result.start, &result.end, new_node(sum));
            a = (a == NULL) ? NULL : a->prev; 
            b = (b == NULL) ? NULL : b->prev; 

        }

        if(carry > 0)
            insert_start(&result.start, &result.end, new_node(carry));
    } 

    return result;
}

BIGINT Fibonacci(int n) {
    if(n <= 2) {
        return bigint("1");
    
    } else {
        BIGINT temp = bigint(NULL);  
        BIGINT f1 = bigint("1");
        BIGINT f2 = bigint("1");
        for(int i = 3; i <= n; i++) {
            temp = f2;
            f2 = add(f1, f2);
            f1 = temp;

        }

        return f2;
    }
}