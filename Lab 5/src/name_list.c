/*
-------------------------------------
File:    name_list.c
Project: 202009_CP264_Lab05_LinkedLists_Given_Code
file description
-------------------------------------
Author:  Heider Ali & Rick Magnotta
ID:      ----------
Email:   heali@wlu.ca & rmagnotta@wlu.ca
Version  10-18-2020
-------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "rm_library.h"
#include "name_list.h"

 void initialize_name_list(sNAME_LIST *name_list)
 //==============================================
 // The empty name_list has both, front and rear pointers set to NULL because the list does NOT contain any nodes, i.e. names.
 // Of course, the count field is set to ZERO for the same reason.
 {
 static char pname[] = "initialize_name_list()";

    if ( name_list != NULL ) {                 // Check for undefined/non-existent "name_list".

	   name_list->front = NULL;               // set front of list pointer to NULL pointer.
	   name_list->rear  = NULL;               // set rear  of list pointer to NULL pointer.
	   name_list->count = 0.0;                // list has ZERO names initially.

    }else {
       sprintf(msg[0], "%s%s", "In Function: ", pname);
       sprintf(msg[1], "%s",   "Internal Error: List not Initialized because it does not exist!");
       report_message(msg, MSG_ERROR);
    }
    return;
 }

 int free_name_list(sNAME_LIST *name_list )
 //=========================================
 // Given the Single-Linked list "name_list", this subprogram CLEANS the list. That is, it frees all of the nodes in the list,
 // including the header node.  It returns a count of the number of nodes freed, including the list header node.
 {
 static char pname[] = "free_name_list()";

 int    n_freed;                               // Count of number of nodes "freed", including header node.
 sNODE *p_ntf;                                 // Pointer to next "Node-To-Free", or node to "clean".

    n_freed = 0;
    if ( name_list != NULL ) {                 // Check for undefined/non-existent "name_list".

       if ( (name_list->front != NULL) &&
    		(name_list->rear  != NULL) &&
			(name_list->count > 0    )   ) {   // Check for empty list
    	                                       // ==> List is NOT empty!
    	  while ( name_list->front != name_list->rear ) {
    		                                   // Traverse the name_list from front to rear, and free every node encountered.

	         p_ntf = name_list->front;         // p_ntf points to the next node to free. This is always the first node in the list.

	         name_list->front = p_ntf->next;   // "de-link" (i.e. drop/remove) the p_ntf node from the list.
                                               // The node following the p_ntf node is now at the front of the list.

	         free(p_ntf);                      // free the de-linked p_ntf node.
	         n_freed++;                        // update freed counter.
          }
    	  free( name_list->front );            // Free the last remaining node in the list.
    	  n_freed++;

       }else {
    	   sprintf(msg[0], "%s%s", "In Function: ", pname);
           sprintf(msg[1], "%s",   "List is EMPTY! Only header node freed.");
           report_message(msg, MSG_INFO);
       }
       free(name_list);                        // Free header node.
       name_list = NULL;
       n_freed++;

    }else {
       sprintf(msg[0], "%s%s", "In Function: ", pname);
       sprintf(msg[1], "%s",   "Internal Error: List not freed because it does not exist!");
       report_message(msg, MSG_ERROR);
    }
    return (n_freed);
 }

 int output_name_list(sNAME_LIST *name_list)               // Linked list of names.
 //==========================================
 {
 static char pname[] = "output_name_list()";
 int    n_printed;                                         // Number of names output/printed.
 sNODE *p_scan;                                            // Scan pointer used to traverse the "name_list".

    if ( name_list != NULL ) {                             // Check for undefined/non-existent "name_list".

       if ( (name_list->front != NULL) &&
    		(name_list->rear  != NULL) &&
    		(name_list->count > 0    )   ) {                // Check for empty list.
    	                                                    // ===>List is NOT EMPTY, so let's print it's contents.
          printf(NL);
          printf("List of Names with duplicates REMOVED:\n");     // Always nice to label the output with a descriptive heading.
          printf("======================================\n");

          n_printed = 0;
          p_scan    = name_list->front;                     // Set p_scan to point to the first node in the last.
          while ( n_printed < name_list->count ) {          // Traverse the name_list from beginning to end and output
    	                                                    // the data content of each node.
    	     printf("%s %s\n", p_scan->name.first_name,
    		                   p_scan->name.last_name);
    	     n_printed++;                                   // Update the counter to keep track of the no. of names printed.
 	         p_scan = p_scan->next;                         // Update the scan pointer to point to the next node.
          }
       }else {
          sprintf(msg[0], "%s%s", "In Function: ", pname);
          sprintf(msg[1], "%s",   "List is EMPTY! Nothing to output/print.");
          report_message(msg, MSG_INFO);
       }
    }else {
       sprintf(msg[0], "%s%s", "In Function: ", pname);
       sprintf(msg[1], "%s",   "Internal Error: List not printed because it does not exist!");
       report_message(msg, MSG_ERROR);
    }
    return (n_printed);
 }

 