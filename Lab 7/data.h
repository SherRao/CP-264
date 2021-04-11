/*
 -------------------------------------------------------
 data.h
 Defines arbitrary data type and data handling function
 types for data structures.
 All data types that are to be stored in data structures
 must provide functions with these signatures.
 -------------------------------------------------------
 Author:  Heider Ali & David Brown
 ID:      999999999 & 999999999
 Email:   heali@wlu.ca & dbrown@wlu.ca
 Version: 2021-03-03
 -------------------------------------------------------
 */
#ifndef DATA_H_
#define DATA_H_

#define DATA_STRING_SIZE 12

                               // defines 'data' as an alias to some other type.
typedef int data;

/**
 * Destroys dynamically allocated data. source is freed and
 * set to NULL.
 * @param source pointer to source data
 */
typedef void (*data_destroy)(data **source);

/**
 * Returns a string version of data.
 * @param string pointer to a string to contain data
 * @param string_size maximum size of string
 * @param source pointer to source data
 * @return pointer to string
 */
typedef char *(*data_to_string)(      char *string,
		                              int   string_size,
		                        const data *source);
/**
 * Compares two data items. Returns:
 *     -1 if source is less than target
 *     1 if source is greater than target
 *     0 if source equals target
 * @param target data to compare to
 * @param source data to be compared
 * @return result of comparison
 */
typedef int (*data_compare)(const data *target,
		                    const data *source);
/**
 * Copies contents of source to target. target is initialized by copy.
 * @param source pointer to source of copy
 * @return pointer to target
 */
typedef data *(*data_copy)(const data *source);

#endif /* DATA_H_ */
