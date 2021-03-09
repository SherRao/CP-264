/*--------------------------------------------------
Project: CP264-a6q1
File:    queue_main.c
Description: public test driver
Author:  HBF  
Version: 2021-02-24
--------------------------------------------------
*/
 
#include <stdio.h>
#include <stdlib.h> 
#include "common.h"
#include "queue.h"

int main(int argc, char* args[]) 
{
  char *str = "10-((3*4)+8)/4";
  if (argc>1) str = args[1]; 
  
  // display an expression
  printf("enqueue:%s\n", str);
  
  // create a queue to store the infix expression
  QUEUE q = {0};
  int sign = 1;
  int num = 0;
  char *p = str;
  while (*p) {
	if ( *p == '-' && (p == str || *(p-1) == '(')  ) { // determine negative sign
      sign = -1;
    } 
	else if (*p >= '0' && *p <= '9'){
	  // use Horner's algorithm to convert digits to int number	
      num = *p-'0';
      while ((*(p+1) >= '0' && *(p+1) <= '9')) {  
         num = num*10 + *(p+1)-'0';  
         p++;
      }
      enqueue(&q, new_node(sign*num, 0));  // signed number
      sign = 1;
    }
    else if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%')
       enqueue(&q, new_node(*p, 1));
    else if (*p == '(')
       enqueue(&q, new_node(*p, 2));
    else if (*p == ')')
       enqueue(&q, new_node(*p, 3));
    else 
       ;  // do nothing, ignore it	
    p++;
  }
   
  printf("display queue:");
  display(q.front);
  printf("\n");

  printf("dequeue:");
  NODE *np = NULL;  
  while (q.front) {
    np = dequeue(&q);
    if (np->type == 0) 
      printf("%d ", np->data);
    else 
      printf("%c ", np->data);
 
    free(np);
  }
  clean_queue(&q);
  printf("\n");
  return 0;
}
