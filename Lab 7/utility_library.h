/*
-------------------------------------
File:    utility_library.h
Project: 202001_CP264_Lab06_Queues_Stacks
file description: Header file for "C" Utility Library.
-------------------------------------
Author:  Rick Magnotta
ID:      xxxxxxxxx
Email:   rmagnotta@wlu.ca
Version  2020-02-06
-------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "rm_library.h"

#ifndef UTILITY_LIBRARY_H_
#define UTILITY_LIBRARY_H_

//===== GLOBAL CONSTANTS ==========================================================================================
#define MAX_MSG_NUM    10                 // Number of message lines in the "msg" message buffer.
#define MAX_MSG_LNG    81                 // Length of a message string: Max of 80 chars +1 for terminating null byte.

//===== VARIABLES and STRUCTURE DEFINITIONS =======================================================================
char msg[MAX_MSG_NUM][MAX_MSG_LNG];       // Message buffer. Can hold MAX_MSG_NUM messages, each MAX_MSG_LNG chars long.

                                          // MESSAGE type or kind of message.
enum msg_kind_type{MSG_INFO,              //   Information.
                   MSG_WARNING,           //   Warning.
                   MSG_ERROR_NONFATAL,    //   NON FATAL Error. (program execution continues)
				   MSG_ERROR_FATAL,       //   FATAL Error.     (program execution is aborted)
                   MSG_END};              //   Program end.

//===================== GLOBAL STACK DEFINITIONS ==============================================================================
                                          //==== DEFINE a character Stack called "call_pname" to store Subprogram Names that
                                          //==== are being called and are in the process of executing.
                                          //==== The stack is used in tracking program execution.
#define MAX_STACK_SZ   100                       // Max. size of stack, that is, maximum number of entries/subprogram names in the stack.
#define MAX_PNAME_LNG   61                       // Max. char. length of a subprogram name.
#define STACK_VAL_LNG  MAX_PNAME_LNG             // Max. character length of stack data element.

typedef char stack;                              // Type of value stored in the "call_pname" stack.
                                                 // (i.e. subprogram name ==> character data)

stack call_pname[MAX_STACK_SZ][STACK_VAL_LNG];   // Stack of subprogram names.
                                                 //   - call_pname stack can hold a maximum of MAX_STACK_SZ values.
                                                 //   - each stack entry value is a character string of STACK_VAL_LNG max length.

stack *p_mxs,                                    // Pointer to Maximum Stack, i.e. last declared position of stack.
      *p_tos,                                    // Pointer to Top-of-Stack
      *p_bos;                                    // Pointer to Bottom-of-Stack

//===== SUBPROGRAM PROTOTYPES ==========================================================================================

                                              // Subprogram to initialize the 2D char message buffer "msg"
void initialize_msg_buff(char msg[MAX_MSG_NUM][MAX_MSG_LNG]);

                                              // Report Message routine to output all of the generated various types of
                                              // output messages. Messages are output in a "standardized" fashion/format.
void report_message(char msg[MAX_MSG_NUM][MAX_MSG_LNG],   // 2D Message Array/Buffer.
                    enum msg_kind_type    msg_kind    );  // Type of message.

void stop_execution();                        // Routine called when an MSG_ERROR_FATAL message is generated to stop
                                              // program execution "gracefully", after a FATAL error.

void print_call_list();                       // Subrotuine to dump/print the contents of the "call_pname" stack.

void push(char *proc_name);                   // Subroutine to "push"/add a subroutine name (i.e. proc_name) onto the "call_pname" stack.

void pop();                                   // Subroutine to "pop"/remove the top subroutine name from the "call_pname" stack.

                                              // Subprogram to "clear", or fill, a given character buffer "buff" with "fill" character.
void clear(      char *buff,                  //   buffer to clear, or fill.
           const long  length,                //   length of buffer
           const char  fill  );               //   fill character.

#endif /* UTILITY_LIBRARY_H_ */
