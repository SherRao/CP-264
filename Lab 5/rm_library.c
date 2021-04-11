/*
-------------------------------------
File:    rm_library.c
Project: 202009_CP264_Lab05_LinkedLists_Given_Code
file description
-------------------------------------
Author:  Heider Ali & Rick Magnotta
ID:      ---------
Email:   rmagnotta@wlu.ca
Version  10-18-2020
-------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "rm_library.h"
#include "name_list.h"



void report_message(char  msg[MAX_MSG_NUM][MAX_MSG_LNG],     // Message buffer
                    enum  msg_kind_type msg_kind       )     // Message kind, i.e. kind of message: INFO, WARNING, or ERROR.
//======================================================
// Given the 2D message buffer msg[][] and the type/kind of message to print, this routine prints the message in a "standardized" format.
// Each message type has a unique prefix which is printed with the first message line to serve as a "label" for the message, and each
// subsequent message line, if present, is indented accordingly.
// Each line of the message buffer is printed sequentially, starting with the first line (index = 0), and ending when either the
// last line of the buffer is printed, or the first NULL line is encountered.
{
static   char pname[] = "report_message";               // sub-program name.

register int  i;
static   char info_prefix[]  = "::> MSG: ";
static   char warn_prefix[]  = "**> WRN: ";
static   char err_prefix[]   = ">>> ERR: ";
static   char end_prefix[]   = "==> END: ";
static   char indent[]       = "       : ";

   printf(NL);                                          // Print a blank line to separate the message from previous output.

   switch (msg_kind) {                                  // Switch on "msg_kind" to determine which message prefix to output!
      case MSG_INFO:
    	 printf(info_prefix);
         break;                                         // A "Switch" statement is the ONLY place where a "break" is allowed because it
                                                        // is part of the "Switch Syntax".
      case MSG_WARNING:
         printf(warn_prefix);
         break;

      case MSG_ERROR:
         printf(err_prefix);
         break;

      case MSG_END:
    	 printf(end_prefix);
         break;

      default:                                           // Always check for an "un-handled" msg_kind!
         printf(">>>>>>: INTERNAL Error in function: %s\n",   pname   );
         printf(">>>>>>: Invalid msg_kind          : [%d]\n", msg_kind);
         break;
   }
                                                         // Output the contents of the "msg" buffer, starting with the first message line.
                                                         // NOTE: The first message line is ALWAYS output because message buffer is
                                                         //       guaranteed to contain at least one message line.

   msg[0][MAX_MSG_LNG -1] = cNUL;                        // Null last position of message, in case message is longer than buffer, or
                                                         // message is not nulled. Can never be too trustworthy when it comes to handling
                                                         // strings in "C".

   printf("%s\n", msg[0]);                               // Always print first message!
   for (int j=0; j < MAX_MSG_LNG; j++) msg[0][j] = cNUL; // Do house-keeping by "Clearing/Nulling" the message line just printed.
                                                         // Scan message array and print any remaining message lines found there.
                                                         // Stop scanning as soon as find a null line (Rember that the entire message
                                                         // buffer was initialized to NULLS at start of Main(). This is why.)
   i = 1;
   while ( (i < MAX_MSG_NUM) && (*msg[i] != cNUL) ) {

      msg[i][MAX_MSG_LNG -1] = cNUL;                        // Always null last position of message, as explained above.

      printf("%s%s\n", indent, msg[i]);                     // Indent all lines of messages following the first message line.

      for (int j=0; j < MAX_MSG_LNG; j++) msg[i][j] = cNUL; // Clear message buffer of message line just printed.
      i++;
   }
   return;
}
