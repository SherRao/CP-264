/*
-------------------------------------
File:    lab5_main.c
Project: 202009_CP264_Lab05_LinkedLists_GivenCode
file description
-------------------------------------
Author:  Heider Ali & Rick Magnotta
ID:      -----------
Email:   heali@wlu.ca & rmagnotta@wlu.ca
Version  10-18-2020
-------------------------------------

Correct Output:
===============
-------------------------------------------------------------------
List of Names with duplicates REMOVED:
======================================
Heider Ali
Ahmed Ibrahim
David Brown
Sukhjit Singh
Rahul Agarwala
Govindaraj Nivedhitha
Don Thenura
Hamdan Kasem
Nash McConnell
Raad Ali
Harshul Mehta
James Wright
Safaa Bedawi
Rick Henderson
Austin Bursey

::> MSG: The list contains 15 unique names.
       : Number of names printed =  15

==> END: Program Terminated.
       : Have a great day.
-------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "rm_library.h"
#include "name_list.h"
// #include <stdbool.h>

int main(int argc, char *argv[]) {
//================================
setbuf(stdout, NULL);

char  filename_in[] = "lab5.txt";    // Input file name.
FILE  *fp_in        = NULL;           // Input file pointer.

int  input_status;                    // Holds status of "fscanf(...)" function.
int  num_printed;                     // Number of names printed/output.
int  return_val;                      // Main program return value to OS (Operating System).

sNODE      *p_node;                   // Declare a pointer to a node in the name_list.
sNAME_LIST *name_list;                // Declare name_list variable

   return_val = 0;                    // Assume all is well.

   name_list = (sNAME_LIST *)malloc(sizeof(sNAME_LIST));           // Instantiate/create the "name_list" header node.
   initialize_name_list(name_list);                                // Initialize the "name_list" header node.


   if ( (fp_in = fopen(filename_in, "r")) == NULL ) {              // Open input file and check if open is successful.

	  sprintf(msg[0], "%s%s", "Cannot open file ", filename_in);   // Core-to-Core I/O. Could have also used the strcat().
	  report_message(msg, MSG_WARNING);
	  return_val = -1;                                             // Get set to have Main return an ERROR condition to OS.

   }else {                                                         // File open was successful!

	  p_node = (sNODE *)malloc(sizeof(sNODE));                     // Instantiate/Create a sNODE.
                                                                   // Read the first line of the input file.
	  input_status = fscanf(fp_in, "%s%s", p_node->name.first_name,
			                               p_node->name.last_name);
	  while ( input_status != EOF ) {                              // Keep reading and inserting until reach EOF (End-Of-File).

		  insert_name_list(name_list, p_node);
	                                                               // Get ready to read next name from input file.
		  p_node = (sNODE *)malloc(sizeof(sNODE));   // Must create/allocate storage for a new sNODE because the previous node was either:
		                                             //    1) inserted in the name_list, if name was not already in the list, or
		                                             //    2) the "node" storage was freed/CLEANED, if name was a duplicate.
		  input_status = fscanf(fp_in, "%s%s", p_node->name.first_name,
		  			                           p_node->name.last_name);
	  }
      fclose(fp_in);                                 // Close input file "here" since it was opened successfully.

      num_printed = output_name_list( name_list );                 // Print list of UNIQUE names.

      sprintf(msg[0], "%s %d %s", "The list contains",name_list->count ,"unique names.");
      sprintf(msg[1], "%s %d",    "Number of names printed = ", num_printed);
      report_message(msg, MSG_INFO);

      free_name_list( name_list );                   // Don't forget to clean up ==> Free/Clean the name_list.
   }

   sprintf(msg[0], "%s", "Program Terminated.");
   sprintf(msg[1], "%s", "Have a great day.");
   report_message(msg, MSG_END);

   return (return_val);                    // Return to OS.
}
