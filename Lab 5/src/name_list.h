/*
-------------------------------------
File:    name_list.h
Project: 202009_CP264_Lab05_LinkedLists_Given_Code
file description
-------------------------------------
Author:  Heider Ali & Rick Magnotta
ID:      ---------
Email:   heali & rma-gnotta@wlu.ca
Version  10-18-2020
-------------------------------------
 */
#ifndef NAME_LIST_H_
#define NAME_LIST_H_

#define MAX_FIRST_NAME_LNG  41                           // Max. size of First  Name field +end byte.
#define MAX_LAST_NAME_LNG   MAX_FIRST_NAME_LNG           // Max. size of Last   Name field +end byte.
#define MAX_MIDDLE_NAME_LNG MAX_FIRST_NAME_LNG           // Max. size of Middle Name field +end byte.


typedef struct {                               // Name Structure storing the First, Last, and Middle name of a person's name.
	char first_name[MAX_FIRST_NAME_LNG];       // Stores the person's first name.
	char last_name [MAX_LAST_NAME_LNG ];       // Stores the person's last  name.
} sNAME;                                       // sNAME is the name given to the person's name structure


typedef struct node{                           // List node structure.
	sNAME        name;                         // Compound field storing the person's name.
    struct node *next;                         // Pointer to an sNODE node.
} sNODE;                                       // sNODE is the name given to the node structure.


typedef struct {
	sNODE *front;                              // Pointer to the FIRST node/name of the sNAME_LIST.
	sNODE *rear;                               // Pointer to the LAST  node/name of the sNAME_LIST.
	int    count;                              // Count of number of nodes/names are present in the sNAME_LIST.
} sNAME_LIST;


//===== SUBPROGRAM PROTOTYPES ===============================================================================================
                                               // Subprogram to initialize the "name_list".
void initialize_name_list(sNAME_LIST *name_list);
                                               // Subprogram to free (i.e. Clean) all the nodes in the "name_list".
int  free_name_list(sNAME_LIST *name_list);
                                               // Subprogram to print the Data content of the "name_list".
int  output_name_list(sNAME_LIST *name_list);
                                               // Subprogram to insert a name in the list, but only if the name is NOT
                                               // already in the list.
void insert_name_list(sNAME_LIST *name_list,
		              sNODE      *node     );

#endif
