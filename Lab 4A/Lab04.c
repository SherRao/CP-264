/*
-------------------------------------
File:    Lab04.c
Project: Lab4_cp264
file description
-------------------------------------
Author:  Nausher Rao
ID:      190906250
Email:   raox6250@mylaurier.ca
Version  2021-02-08
-------------------------------------

Marking Scheme (Total 6 Marks):
==============  =============
a) Subprogram "write_text_inorder(...)":
   - Correct output             =  1
   - Output Heading and
     use of report_message()    =  1 (Call report_message() to output an "MSG_INFO" message if nothing to print).

b) Subprogram "write_text_reverse(...)":
   - Correct output             =  1
   - Output Heading, and
     use of report_message()    =  1 (Call report_message() to output an "MSG_INFO" message if nothing to print).

c) Create a new enumerated message type,
   "MSG_END", and show its use  =  1

d) Proper indentation,
   descriptive variable names,
   documentation/comments       =  1
                                  ---
                           Total   6
Penalties:
=========
- Hard-coding                            = -1
- Use of Break, Continue, Go To          = -1 (NOTE: Break allowed in "Switch" statement.)
  (i.e. Spaghetti code)
- Convoluted logic                       = -1
- Multiple "return" from main/subprogram = -1
- Presence of Compiler Warnings          = -1

- NOTE: Program MUST Compile clean and MUST Execute, otherwise a mark of ZERO is given for the lab.
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "ha_library.h"

//===== GLOBAL FUNCTION PROTOTYPES ==============================================================
int  read_text         (char *p_text[],
		                FILE *fp      );

void write_text_inorder(char *p_text[],
		                int   nlines  );

void write_text_reverse(char *p_text[],
		                int   nlines  );

void report_message    (char   msg[MAX_MSG_NUM][MAX_MSG_LNG],
                        enum   msg_kind_type    msg_kind    );


int main(int argc, char *argv[]) {
//================================
setbuf(stdout, NULL);

int  nlines;                          // No. of lines read from input file.
int  return_val;                      // Main program return value to OS (Operating System).

char *p_text[MAX_NUM_LINES];          // Array of pointers to "char"
                                      // Have a total number of MAX_NUM_LINES pointers.
char  filename_in[] = "text.txt";     // Input file name.
FILE  *fp_in        = NULL;           // Input file pointer.

   return_val = 0;                    // Assume all is well.

   for (int i=0; i < MAX_MSG_NUM; i++)                             // Initialize "msg" message buffer by filling entire buffer with NULLs.
      for (int j=0; j < MAX_MSG_LNG; j++) msg[i][j] = cNUL;

   if ( (fp_in = fopen(filename_in, "r")) == NULL ) {              // Open input file and check if open is successful.

	  sprintf(msg[0], "%s%s", "Cannot open file ", filename_in);   // Core-to-Core I/O. Could have also used the strcat() in this case.
	  report_message(msg, MSG_WARNING);
	  return_val = -1;                                             // Get set to have Main return an ERROR condition to OS.

   }else {                                                         // File open was successful!
	                                                               // Read the entire input text in the "p_text" array of char pointers.
      if ( (nlines = read_text(p_text, fp_in)) >= 0 ) {

         write_text_inorder(p_text, nlines);                       // Call subprogram to print in order.
         write_text_reverse(p_text, nlines);                       // Call subprogram to print in reverse order.

	  }else {                              // Handle excessive number of input lines. Indicated by "nlines = -1"
		 sprintf(msg[0], "%s",     "Input file too large to process.");
		 sprintf(msg[1], "%s[%d]", "Max. number of input lines allowed = ", MAX_NUM_LINES);
		 sprintf(msg[2], "%s",     "Program Execution Aborted.");
		 report_message(msg, MSG_ERROR);
		 return_val = -1;                  // Set up to return ERROR condition (-1) to OS.
	  }

      fclose(fp_in);                       // Close input file "here" since it was opened successfully.
   }

   //printf("Program Terminated. Have a great day.");
   sprintf(msg[0], "Program Terminated.");
   sprintf(msg[1], "Have a great day.");
   report_message(msg, MSG_END);

   return (return_val);                    // Return to OS.
}

int read_text(char *p_text[],              // Array of pointers to char.
		      FILE *fp      )              // Input file pointer.
//===========================
// This function reads consecutive lines of text from the input file "fp", until either the end of file is reached, or
// the end of the array of pointers is reached.
// Each input line is saved/stored in dynamic storage and it is accessed/referenced by a pointer of the p_text array.
// That is, p_text[0] points to the FIRST input line,
//          p_text[1] points to the SECOND input line, and so on.
// The function returns:
//     1) The array of pointers "p_text" that point to each input line.
//     2) The number of lines read, if all went well, otherwise
//     3) Return -1, if an error has occurred.
{
int   i;                                   // Loop index.
int   nlines;                              // Line counter of lines read.
int   line_lng;                            // Length of current input line.
char  line[MAX_LINE_LNG];                  // Local storage for the current line of text just read.
char  *p;                                  // Pointer to dynamically allocated storage.
int   return_val;                          // Value returned by the function.

   nlines     = 0;
   return_val = 0;                         // So far, all is well.

   while ( (fgets(line, MAX_LINE_LNG, fp) != NULL) && (return_val >= 0) ) {

	  i = 0;
	  while ((line[i] != cNUL) && (i <= MAX_LINE_LNG) ) {      // Scan input line and null any NL or CR characters.
		                                                       // This will make your program very portable because depending
		                                                       // on the computer system, a data line in a file can be terminated
		                                                       // by any one of the following "line-terminator":
		                                                       //    "\n", "\r", "\n\r", or "\r\n"
	     if ( (line[i] == cNL) || (line[i] == cCR) ) line[i] = cNUL;
	     i++;
      }

      nlines++;                              // Increase line count since we have read another line of text.
      if ( nlines <= MAX_NUM_LINES ) {       // Ensure that we have room in our p_text array of pointers for the
    	                                     // input line just read.

         line_lng = strlen(line);
  	     if ( (p = malloc(line_lng +1)) != NULL ) {  // Create dynamic storage for input line and check that
	    	                                         // requested storage is granted.
	        strncpy(p, line, line_lng);              // Copy input line to dynamic string pointed to by "p"
	        p[line_lng] = cNUL;                      // and null the string.

	    	p_text[nlines -1] = p;                   // Update "p_text" pointer array element at position [nlines -1]
	    	                                         // to point to dynamic storage "p".
	    	return_val = nlines;

	     }else return_val = -1;              // Failed to allocate dynamic storage.
      }else return_val = -1;                 // Have exceeded Maximum number of input lines that can be stored in
      	                                     // pointer array.
   }
   return(return_val);
}

void write_text_inorder(char *p_text[],      // Array of pointers to lines of input.
		                int   nlines  )      // Number of input lines pointed to/referenced by array of pointers.
//=====================================
// This subroutine prints all input lines of text referenced by the "p_text" array of pointers.
// Input lines are printed in the SAME order as they were read in.
// A suitable heading is printed to indicate the nature of the output.
// The report_message() routine is called to output an appropriate "MSG_INFO" message if there are no lines of text to print.
{

	if (nlines == 0) {
		sprintf(msg[0], "No lines of text to print.");
		sprintf(msg[1], "Terminating program execution.");
		report_message(msg, MSG_INFO);

	}

	else {
		sprintf(msg[0], "Lines available to print, now running write_text_inorder.");
		report_message(msg, MSG_INFO);

		for (int i = 0; i < nlines; i++){
			printf("%s\n", *(p_text + i));
		}
	}

   return;
}

void write_text_reverse(char *p_text[],          // Array of pointers to lines of input.
		                int   nlines  )          // Number of input lines pointed to/referenced by array of pointers.
//=====================================
// This subroutine prints all input lines of text referenced by the "p_text" array of pointers.
// Input lines are printed in the REVERSE order that they were read in.
// A suitable heading is printed to indicate the nature of the output.
// The report_message() routine is called to output an appropriate "MSG_INFO" message if there are no lines of text to print.
{

   if (nlines == 0) {
	   sprintf(msg[0], "No lines of text to print.");
	   sprintf(msg[1], "Terminating program execution.");
	   report_message(msg, MSG_INFO);
   }

   else {
	   sprintf(msg[0], "Lines available to print, now running write_text_reverse.");
	   report_message(msg, MSG_INFO);

	   for (int i = 0; i < nlines + 1; i++) {
		   printf("%s\n", *(p_text + (nlines - i)));
	   }
   }

   return;
}

void report_message(char  msg[MAX_MSG_NUM][MAX_MSG_LNG],     // Message buffer
                    enum  msg_kind_type   msg_kind     )     // Message kind, i.e. kind of message: INFO, WARNING, or ERROR.
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
static	 char end_prefix[]   = "==> END: ";
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
