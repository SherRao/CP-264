/*--------------------------------------------------
Project: CP264-a6q2
File:    stack_main.c
Description: public test driver
Author:  HBF  
Version: 2021-02-24
--------------------------------------------------
*/

#include <stdio.h>
#include <malloc.h> 
#include "common.h" 
#include "stack.h"

int main(int argc, char* args[]) {
  char *str = "12 34 56 78 90 + - * /";
  if (argc>1) str = args[1]; 
  
  printf("str:%s\n", str);
 
  // parse 
  STACK stack = {0};
  int sign = 1;
  int num = 0;  
  char *p = str;
  while (*p) {
	if ( *p == '-' && (p == str || *(p-1) == ' ')  ) { // determine negative sign
      sign = -1;
    } 
	else if (*p >= '0' && *p <= '9'){
      num = *p-'0';
      while ((*(p+1) >= '0' && *(p+1) <= '9')) {  
         num = num*10 + *(p+1)-'0';  
         p++;
      }
	  push(&stack, new_node(num, 0));
      sign = 1;  
    }
    else if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%')
       push(&stack, new_node(*p, 1));
    else if (*p == '(')
       push(&stack, new_node(*p, 2));
    else if (*p == ')')
       push(&stack, new_node(*p, 3));
    else 
       ;	// ignore
    p++;
  }
    
  printf("display stack:");
  display(stack.top);
  printf("\n");
  
  printf("pop:");
  NODE *np = NULL;  
  while (stack.top) {
    np = pop(&stack);
      if (np->type == 0) 
      printf("%d ", np->data);
    else 
      printf("%c ", np->data);  
    free(np);
  }
  printf("\n");
  clean_stack(&stack);
  
  return 0;
}


