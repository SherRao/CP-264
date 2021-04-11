/*
-------------------------------------
File:    rm_library.h
Project: n/a
file description: Rick Magnotta's special definition general header file.
-------------------------------------
Author:  Rick Magnotta
ID:      xxxxxxxx
Email:   rmagnotta@wlu.ca
Version  2020-02-06
-------------------------------------
 */

#ifndef RM_LIBRARY_H_         // RM_LIBRARY_H (Rick Magnotta Library of definitions)
#define RM_LIBRARY_H_
                              // Define machine-independent TRUE and FALSE values
#ifdef TRUE
   #undef TRUE
   #undef FALSE
#endif
#define TRUE  (1==1)
#define FALSE (0==1)

//===== GLOBAL MACRO DEFINITIONS ==================================================================================
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

//::::: Some very useful STRING Processing Definitions ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                                                    // Comparison of entire strings.
#define sEQ(s1,s2)      (!strcmp((s1),(s2)))
#define sNE(s1,s2)      ( strcmp((s1),(s2)))
#define sLT(s1,s2)      ( strcmp((s1),(s2)) <  0)
#define sLE(s1,s2)      ( strcmp((s1),(s2)) <= 0)
#define sGT(s1,s2)      ( strcmp((s1),(s2)) >  0)
#define sGE(s1,s2)      ( strcmp((s1),(s2)) >= 0)
                                                    // Comparison of up to a maximum of "n" characters of given strings.
#define snEQ(s1,s2,n)   (!strncmp((s1),(s2),(n)))
#define snNE(s1,s2,n)   ( strncmp((s1),(s2),(n)))
#define snLT(s1,s2,n)   ( strncmp((s1),(s2),(n)) <  0)
#define snLE(s1,s2,n)   ( strncmp((s1),(s2),(n)) <= 0)
#define snGT(s1,s2,n)   ( strncmp((s1),(s2),(n)) >  0)
#define snGE(s1,s2,n)   ( strncmp((s1),(s2),(n)) >= 0)
                                                    // Is a string EMPTY, BLANK, etc. ?
#define sISempty(s)     ((*s) == cNUL)
#define sISNOTempty(s)  (!(sISempty((s))))

#define sISblank(s)     (strspn((s),(BLK)) == strlen((s)))
#define sISNOTblank(s)  (!(sISblank((s))))

#define sISzero(s)      (strspn((s),"0") == strlen((s)))

#define sHasValue(s)    ( (sISNOTempty((s))) && (sISNOTblank((s))))
#define sHasNoValue(s)  (!(sHasValue((s))))
                                                         // Null the destination string, copy the source string, and null the end byte!
#define my_strncpy(s1,s2,n)  {clear((s1),(n),cNUL); \
                              strncpy((s1),(s2),(n)); s1[(n)]=cNUL;}

// ===== GLOBAL STATEMENT FUNCTION DEFINITIONS ====================================================================
#define  F_MIN(v1,v2) (((v1) <  (v2))? (v1):(v2))        // Return the less    of v1 and v2
#define  F_MAX(v1,v2) (((v1) >  (v2))? (v1):(v2))        // Return the greater of v1 and v2
#define ZF_MIN(v1,v2) (F_MAX(0, (F_MIN((v1),(v2)))))     // Like F_MIN, but lower bounds the result at ZERO
#define ZF(v)         (F_MAX(0, (v)))                    // Lower bounds the value "v" at ZERO.
#define  F_NOT(v)     (((v) == TRUE)? FALSE:TRUE)        // Logical Negation.
#define  F_ABS(v)     (((v) >= 0   )? (v):(-(v)))        // Absolute value

//===== PSEUDO-TYPES DEFINITIONS ==================================================================================
typedef unsigned int bool;             // Define "bool" to hold boolean values TRUE or FALSE


#endif /* RM_LIBRARY_H_ */
