/*
-------------------------------------
File:    generic_type.h
Project: stack_queue
file description
-------------------------------------
Author:  Heider Ali
ID:      9999999999
Email:   heali@wlu.ca
Version  2020-10-29
-------------------------------------
 */
#ifndef GENERIC_TYPE_H
#define GENERIC_TYPE_H

typedef char* ItemType;// define generic type

// Values and format specifiers required for each specific generic type
#define ITEMTYPE_NONE ""

#define ITEMTYPE_FORMAT_SPEC "%s"
#define ITEMTYPE_PRINT(item) printf(ITEMTYPE_FORMAT_SPEC, item);

#endif
