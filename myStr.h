//
// Created by mikipaw on 20.09.2020.
//
#pragma once
#ifndef ONEGIN_MYSTR_H
#define ONEGIN_MYSTR_H

#define TRUE 1
#define FALSE 0

//#include <cstring>
#include <cctype>

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


simple_string& operator<<(simple_string& sstr, const char* str){
    char c = 1;
    int size = 0;
    while(c != '\0'){
        c = str[size++];
    }
    sstr.string = (char*) calloc(size, sizeof(char));
    sstr.string = (char*) str;
    sstr.size = size;
    return sstr;
}

int simple_string_comparator(const simple_string& string1, const simple_string& string2){
    return str_cmp_4_sort(string1.string, string2.string);
}

void quick_sort_strings(simple_string* array, int left, int right, const char* order){
    simple_string tmp = array[left];
    int l_hold = left, r_hold = right, mdl = 0;
    while(left < right){
        if(str_cmp(order, "FROM END")){
            while((str_cmp_4_sort_from_end(array[right], tmp) >= 0) && (left < right)) right--;
            if(left != right) array[left++] = array[right];
            while((str_cmp_4_sort_from_end(array[left], tmp) <= 0) && (left < right)) left++;
            if(left != right) array[right--] = array[left];
        }
        else{
            while((str_cmp_4_sort(array[right].string, tmp.string) >= 0) && (left < right)) right--;
            if(left != right) array[left++] = array[right];
            while((str_cmp_4_sort(array[left].string, tmp.string) <= 0) && (left < right)) left++;
            if(left != right) array[right--] = array[left];
        }

    }
    array[left] = tmp;
    mdl = left;
    left = l_hold;
    right = r_hold;
    if(left < mdl)  quick_sort_strings(array, left, mdl - 1, order);
    if(right > mdl) quick_sort_strings(array, mdl + 1, right, order);
}

int str_cmp_4_sort_from_end(const simple_string& str1, const simple_string& str2){
    int i = str1.size, j = str2.size;
    if(i == 0 || j == 0) return i - j;
    i--;
    j--;

    while(i >= 0 && j >= 0){
        while(!(isalpha(str1.string[i]))) i--;
        while(!(isalpha(str2.string[j]))) j--;

        if     (i < 0 && j < 0) return 0;
        else if(i < 0 || j < 0) return i - j;

        while(str1.string[i] == str2.string[j] && i > 0 && j > 0){
            i--;
            j--;
        }
        return str1.string[i] - str2.string[j];
    }
    return 0;
}


int str_cmp_4_sort(const char* str1, const char* str2){
    int i = 0, j = 0;
    while(TRUE){
        while(!(isalpha(str1[i]) || str1[i] == '\0')) i++;
        while(!(isalpha(str2[j]) || str2[j] == '\0')) j++;

        if(str1[i] == '\0' &&
            str2[j] == '\0') return 0;

        if(str1[i] == str2[j]){
            i++;
            j++;
        }
        else return str1[i] - str2[j];
    }
}


int str_cmp(const char* str1, const char* str2){
    int i = 0;
    while(TRUE){
        if(str1[i] == '\0' && str2[i] == '\0') return TRUE;
        if(str1[i] == str2[i]){
            ++i;
            continue;
        }
        return FALSE;
    }
}



#endif //ONEGIN_MYSTR_H
