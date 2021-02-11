/*
-------------------------------------
File:    ha_library.h
Project: Lab4_cp264
file description
-------------------------------------
Author:  Riley Adams
ID:      190416070
Email:   adam6070@mylaurier.ca
Version  2021-02-08
-------------------------------------
 */

#ifndef HA_LIBRARY_H_
#define HA_LIBRARY_H_

 // Define machine-independent TRUE and FALSE values
#ifdef TRUE
   #undef TRUE
   #undef FALSE
#endif
#define TRUE  (1==1)
#define FALSE (0==1)

//===== GLOBAL MACRO DEFINITIONS ================================================================
#define  NL      "\n"         // New Line string
#define cNL      '\n'         // New Line char
#define  LF      "\n"         // Line Feed string
#define cLF      '\n'         // Line Feed char
#define  CR      "\r"         // Carriage Return string
#define cCR      '\r'         // Carriage Return char
#define  CRLF    "\r\n"       // Carriage Return/Line Feed
#define  LFCR    "\n\r"       // Line Feed/Carriage Return
#define  FF      "\f"         // Form Feed
#define  NUL     "\0"         // Null string
#define cNUL     '\0'         // Null character
#define  BLK     " "          // Single Blank string
#define cBLK     ' '          // Single Blank character

#define cUScore  '_'          // Underscore character
#define  UScore  "_"          // Underscore string.
#define cZERO    '0'          // Single ZERO character

#define  HTAB    "\t"         // Horizontal Tab string
#define cHTAB    '\t'         // Horizontal Tab character
#define  VTAB    "\v"         // Vertical Tab string
#define cVTAB    '\v'         // Vertical Tab character
#define  ESC     "\x1B"       // Escape string [hex(1B) = dec(27)]

// ===== GLOBAL STATEMENT FUNCTION DEFINITIONS ====================================================================
#define  F_MIN(v1,v2) (((v1) <  (v2))? (v1):(v2))        // Return the less    of v1 and v2
#define  F_MAX(v1,v2) (((v1) >  (v2))? (v1):(v2))        // Return the greater of v1 and v2
#define ZF_MIN(v1,v2) (F_MAX(0, (F_MIN((v1),(v2)))))     // Like F_MIN, but lower bounds the result at ZERO
#define ZF(v)         (F_MAX(0, (v)))                    // Lower bounds the value "v" at ZERO.
#define  F_NOT(v)     (((v) == TRUE)? FALSE:TRUE)        // Logical Negation.
#define  F_ABS(v)     (((v) >= 0   )? (v):(-(v)))        // Absolute value

//===== GLOBAL Constants ==========================================================================================
#define MAX_NUM_LINES 500             // Max. number of lines.
#define MAX_LINE_LNG   81             // Max. length of line. One extra byte for terminating null.

#define MAX_MSG_NUM   10              // Number of message lines.
#define MAX_MSG_LNG  133              // Length of a message string: Max of 132 chars +1 for terminating null byte.

//===== GLOBAL VARIABLES and STRUCTURE DEFINITIONS ================================================================
char msg[MAX_MSG_NUM][MAX_MSG_LNG];   // Message buffer. Can hold MAX_MSG_NUM messages, each MAX_MSG_LNG chars long.

                                      // MESSAGE type or kind of message.
enum msg_kind_type{MSG_INFO,          //   Information.
                   MSG_WARNING,       //   Warning.
                   MSG_ERROR,         //   Error.
                   MSG_END};          //   Program end.

#endif /* HA_LIBRARY_H_ */
