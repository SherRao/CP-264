/*
-------------------------------------
File:    utility_library.c
Project: 202001_Cp264_Lab06_Queues_Stacks
file description: "C" source file for utility subprograms.
-------------------------------------
Author:  Rick Magnotta
ID:      xxxxxxxxx
Email:   rmagnotta@wlu.ca
Version  2020-02-14
-------------------------------------
 */

#include "utility_library.h"

void initialize_msg_buff(char msg[MAX_MSG_NUM][MAX_MSG_LNG])
//==========================================================
// Given the 2D character message buffer array, "msg", this routine fills it's entire contents with NULL.
{
static char pname[] = "initialize_msg_buff";
   push(pname);

   for (int i=0; i < MAX_MSG_NUM; i++)                     // Visit each char element of the array and initialize it to NULLs.
	   for (int j=0; j < MAX_MSG_LNG; j++) msg[i][j] = cNUL;

   pop();
   return;
 }

void report_message(char  msg[MAX_MSG_NUM][MAX_MSG_LNG],     // Message buffer
                    enum  msg_kind_type msg_kind       )     // Message kind, i.e. kind of message: INFO, WARNING, or ERROR.
//======================================================
// Given the 2D message buffer msg[][] and the type/kind of message to print, this routine prints the message in a "standardized" format.
// Each message type has a unique prefix which is printed with the first message line to serve as a "label" for the message, and each
// subsequent message line, if present, is indented accordingly.
// Each line of the message buffer is printed sequentially, starting with the first line (index = 0), and ending when either the
// last line of the buffer is printed, or the first NULL line is encountered.
//
// NOTE: push() and pop() are not used in this utility routine in order to avoid an infinite calling loop.
{
static char pname[] = "report_message";
register int  i;
static   char info_prefix[] = "::> MSG: ";
static   char warn_prefix[] = "**> WRN: ";
static   char err_prefix[]  = ">>> ERR: ";
static   char end_prefix[]  = "==> END: ";
static   char indent[]      = "       : ";

   printf(NL);                                   // Print a blank line to separate the message from previous output.

   switch (msg_kind) {                           // Switch on "msg_kind" to determine which message prefix to output!
      case MSG_INFO:
    	 printf(info_prefix);
         break;                                  // A "Switch" statement is the ONLY place where a "break" is allowed
                                                 // because it is part of the "Switch Syntax".
      case MSG_WARNING:
         printf(warn_prefix);
         break;

      case MSG_ERROR_NONFATAL:                   // Print error prefix. Note both NONFATAL and FATAL errors have the
      case MSG_ERROR_FATAL:                      // same message prefix, and are hence, processed together.
         printf(err_prefix);
         break;

      case MSG_END:
    	 printf(end_prefix);
         break;

      default:                                           // Always check for an "unhandled" msg_kind!
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

   i = 1;
   while ( (i < MAX_MSG_NUM) && (*msg[i] != cNUL) ) {    // Scan message array and print any remaining message lines found there.
                                                         // Stop scanning as soon as find a null line (Rember that the entire message
                                                         // buffer was initialized to NULLS at start of Main(). This is why.)

      msg[i][MAX_MSG_LNG -1] = cNUL;                        // Always null last position of message, as explained above.

      printf("%s%s\n", indent, msg[i]);                     // Indent all lines of messages following the first message line.

      for (int j=0; j < MAX_MSG_LNG; j++) msg[i][j] = cNUL; // Clear message buffer of message line just printed.
      i++;
   }
                                   // We have printed the requested "message". So, let's check if we have a FATAL ERROR, and if so,
                                   // then let's call the "stop_execution()" routine to "gracefully" STOP/ABORT program execution.
                                   // Otherwise, simply return to calling subprogram and continue executing.
   if ( msg_kind == MSG_ERROR_FATAL ) stop_execution();

   return;
}

void stop_execution()
//===================
// This routine is called when a FATAL error condition has occurred.
// It is the responsibility of this routine to carry out all of the "House-Keeping" tasks before aborting program execution.
// Because program execution is stopped, or aborted, under "our" control, rather than a program crash, we refer to this
// type of action as "Graceful Program Termination".
// The only house-keeping duty performed presently, before EXITING to the Operating System (OS), is to print the
// subprogram "call list", as shown below. However, in typical "well written" professional application some of the
// duties charged to this type of routine would be:
//      - ROLL Back any "uncommitted" Data Base changes.
//      - Disconnect from the Data Base(s).
//      - Free any dynamically allocated memory.
//      - Close ALL opened input and output files.
//      - Notify any external system and/or supervisor that a FATAL error has occurred and the program task has not COMPLETED
//        as expected.  This would be a welcomed message/wake-up call if the aborted program is a mission critical application
//        such as a Payroll program that MUST complete successfully in order for employees to get paid on time!
//
// NOTE: push() and pop() are not used in this utility routine in order to avoid an infinite calling loop.
{
   char msg_1[] = ">>>>> :::::::::: Program Execution ABORTED :::::::::: <<<<<\n";
   char msg_2[] = ">>>>> EXIT MAIN: ======= WITH FATAL ERROR(S) ==============\n";

   printf(NL);
   printf(NL);

   printf(msg_1);
   printf(NL);
   printf(msg_2);

   print_call_list();           // Print the subprogram call list in LIFO order.

   exit(-1);                    // <<<=== Exit program and return an ERROR status (i.e. -1) to the OS (Operating System).
   return;
 }

void print_call_list()
//====================
// Dump/print contents of subprogram calling stack (LIFO).
// NOTE: push() and pop() are not used in this utility routine because
//       this is the routine that dumps/prints the stack contents.
{
register stack *p;              // Local stack scan pointer.

   printf(NL);
   printf(NL);
   printf("=====    Subprogram Calling Sequence    =====\n");
   printf("=====       (Most recent at TOP)        =====\n");
   printf("=============================================\n");

   for (p = p_tos; (p > p_bos); p -= STACK_VAL_LNG)  printf("%s\n", p);

   return;
}

 void push(char *proc_name)
 //========================
 // Utility subroutine which adds/pushes the "proc_name" subroutine name onto the "call_pname" stack.
 // This subroutine assumes that the "call_pname" stack, and it's associated pointers: p_top, p_bot, and p_mxs
 // have been previously GLOBABLLY declared, but not initialized.
 // Initialization of the "call_pname" stack, and stack pointers, is AUTOMATICALLY performed here by the use of
 // the local static variable "initialize", as shown below.
 // For "your" code to work with other program components, it must conform to the following:
 //   1) The "p_mxs" pointer MUST always point to the "maximum" declared element of the "call_pname" stack.
 //   2) The "p_bos" pointer MUST always point to the first element (i.e. index[0]) of the "call_pname" stack.
 //   3) The "p_tos" pointer MUST always point to the TOP-OF-STACK of the "call_pname" stack.
 // NOTE: In order to keep the stack pointer logic simple and direct, the first (i.e. bottom) stack element position is
 //       sacrificed to remain unused! That is, no "proc_name" is stored in index[0].
 //
 // NOTE: push() and pop() are not used in this utility routine in order to avoid an infinite calling loop.
 {
 static char pname[]    = "push";
 static bool initialize = TRUE;           // Static local variable "initialize" is set to TRUE ONLY the first time this
                                          // routine is called.
 int lng;

    if ( initialize ) {
   	                                      // The global "call_pname" stack is not yet initialized, so let's do it now.
       initialize = FALSE;                // Because the local variable "initialize" is "static", then this initialization
                                          // step is performed ONLY the FIRST time that the "push(..)" routine is called, as desired!

       p_bos = call_pname[0];                     // Bottom-of-Stack pointer ALWAYS points to First slot of stack.
       p_tos = p_bos;                             // Top-of-Stack pointer is initially set to point to bottom-of-stack, also.
                                                  // Thus the STACK EMPTY condition is identified by "t_tos = t_bos".
                                                  // This means that the first stack position (call_pname[0]) is sacrificed
                                                  // in favour of simplifying the logic, and holds no value.
       p_mxs = call_pname[MAX_STACK_SZ -1];       // The p_mxs pointer always points to the "last/maximum" stack position.
    }

    if (p_tos < p_mxs) {                          // Check if we have room on the Stack to push a proc_name.

       p_tos += STACK_VAL_LNG;                    // Increment Top-Of-Stack pointer to next available slot.

       lng = ZF_MIN(strlen(proc_name), STACK_VAL_LNG -1);    // Truncate "proc_name" if it is longer than STACK_VAL_LNG.
                                                             // to prevent string run-off.
       my_strncpy(p_tos, proc_name, lng);                    // Copy subprogram name to top-of-stack position.
                                                             //   -NOTE: The my_strncpy() clears the entire p_tos element.
    }else {
       sprintf(msg[0], "%s%s", "INTERNAL FATAL ERROR in function: ", pname);
       sprintf(msg[1], "%s",   "::: call_pname Stack Overflow!");
       report_message(msg, MSG_ERROR_FATAL);
    }
    return;
 }

 void pop(void)
 //============
 // Utility subroutine which removes/pops a subroutine name from the subroutine call stack "call_pname".
 // This subroutine assumes that the "call_pname" stack has been previously GLOBABLLY defined and initialized, along with the
 // stack pointers:  p_tos (top-of-stack) and p_bos (bottom-of-stack).
 // For "your" code to work with other program components, it must conform to the following:
 //   1) The "p_mxs" pointer MUST always point to the "maximum" declared element of the "call_pname" stack.
 //   2) The "p_bos" pointer MUST always point to the first element (i.e. index[0]) of the "call_pname" stack.
 //   3) The "p_tos" pointer MUST always point to the TOP-OF-STACK of the "call_pname" stack.
 // NOTE: In order to keep the stack pointer logic simple and direct, the first (i.e. bottom) stack element position is
 //       sacrificed to remain unused! That is, no "proc_name" is stored in index[0].
 //
 //  NOTE: push() and pop() are not used in this utility routine in order to avoid an infinite calling loop.
 {
 static char pname[] = "pop";

    if (p_tos > p_bos) {                           // Have at lease ONE value in the stack, so let's pop it by simply
       p_tos -= STACK_VAL_LNG;                     // decrementing the p_tos pointer, accordingly.

    }else {
    	                                           // Stack is empty, but have been called to perform a pop() operation,
    	                                           // resulting in an underflow condition.
       sprintf(msg[0], "%s%s", "INTERNAL FATAL ERROR in function: ", pname);
       sprintf(msg[1], "%s",   "::: call_pname Stack Underflow!");
       report_message(msg, MSG_ERROR_FATAL);
    }
    return;
 }

 void clear(      char *buff,      // Character Buffer to clear/fill
            const long  size,      // Size/length of buffer, including the terminating NULL position.
            const char  fill)      // Fill character.
 //==========================
 // This subprogram fills the given character buffer "buff" with the given "fill" character, as explained below.
 // The length of the string pointed to by *buff is the "DECLARED SIZE" of the string.
 // That is, the Declared Size includes the number of characters comprising the string PLUS the terminating NULL character.
 // Eg. if declare:  char str[10];
 //           then:  "str" can store a maximum of 9 chars.
 //                  The 10th position is reserved for the string terminator char cNUL.
 //     eg: clear(str, 10, cNUL) ===> All 10 positions are filled with cNUL.
 //         clear(str, 10, cBLK) ===> The first 9 bytes are filled with cBLK.
 //                                   The 10th byte contains the cNUL character.
 {
 register int  i;

    if (size > 0) {
       for (i=1; i<size; i++) *buff++ = fill;   // By starting at (i=1) we loop (size-1) times AND the buff pointer points to the
                                                // the last BYTE position, ready to insert an end NULL char.
       *buff = cNUL;                            // Ensure end of string is NULLED
    }
    return;
 }
