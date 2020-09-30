//
// Created by mikipaw on 20.09.2020.
//
#ifndef ONEGIN_MYSTR_H
#define ONEGIN_MYSTR_H

#define TRUE 1
#define FALSE 0

//#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>

/*!
 *  \struct simple_string
 *  \param string a char*
 *  \param size a size_t - size of string
 */
//TODO: make it class
struct simple_string{
    simple_string() = default;
    char* string = nullptr;
    size_t size = 0;
};


/*!
*  \function int str_cmp(const char* str1, const char* str2)
*  \brief Function checks if 2 strings are equal
*  \param str1 a const char*
*  \param str2 a const char*
*  \return an integer - true(1) or false(0)
*/
int str_cmp(const char* str1, const char* str2);


/*!
*  \function int str_cmp_4_sort(const char* str1, const char* str2)
*  \brief Function compares 2 strings
*  \param str1 a const char*
*  \param str2 a const char*
*  \return an integer: >0 if str1 > str2, =0 if str1 == str2, <0 if str1 < str2
*/
int str_cmp_4_sort(const char* str1, const char* str2);

/*!
*  \function int str_cmp_4_sort_from_end(const char* str1, const char* str2)
*  \brief Function compares 2 strings from last symbol
*  \param str1 a const simple_string
*  \param str2 a const simple_string
*  \return an integer: >0 if str1 > str2, =0 if str1 == str2, <0 if str1 < str2
*/
int str_cmp_4_sort_from_end(const simple_string& str1, const simple_string& str2);


/*!
*  \function void quick_sort_strings(char** array, int left, int right, const char* order = "FROM BEGIN");
*  \brief Function sorts the array of strings
*  \param array a char** - array of strings
*  \param left an integer - left border of array
*  \param right an integer - right border of array
*  \param order a const char*
*  \return nothing
*/
void quick_sort_strings(simple_string* array, int left, int right, const char* order = "FROM BEGIN");

/*!
*  \function void Print_In_File(simple_string* array, FILE* result_file);
*  \brief Function prints the array of strings in file
*  \param array a char** - array of strings
*  \param result_file a FILE*
*  \return nothing
*/
void Print_In_File(simple_string* pointers, FILE* result_file, int number_of_lines, int number_of_empty_lines = 0);


/*!
*  \function size_t Size_of_file(FILE* name_of_file);
*  \brief Function finds size of file
*  \param name_of_file - a FILE*
*  \return size_t - number of chars
*/
size_t Size_of_file(FILE* name_of_file);

simple_string& operator<<(simple_string& sstr, const char* str);

#endif //ONEGIN_MYSTR_H
