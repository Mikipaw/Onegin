//
// Created by pawlo on 20.09.2020.
//
#pragma once
#ifndef ONEGIN_MYSTR_H
#define ONEGIN_MYSTR_H

#define TRUE 1
#define FALSE 0

#include <cstring>
#include <cctype>

int str_cmp(const char* str1, const char* str2);
int Compare(const void* str1, const void* str2);
int str_cmp_4_sort(const char* str1, const char* str2);
int str_cmp_4_sort_from_end(const char** str1, const char** str2);

void quick_sort_strings(char** array, int left, int right){
    char* tmp = array[left];
    int l_hold = left, r_hold = right, mdl = 0;
    while(left < right){
        while((str_cmp_4_sort(array[right], tmp) >= 0) && (left < right)) right--;
        if(left != right) array[left++] = array[right];
        while((str_cmp_4_sort(array[left], tmp) <= 0) && (left < right)) left++;
        if(left != right) array[right--] = array[left];
    }
    array[left] = tmp;
    mdl = left;
    left = l_hold;
    right = r_hold;
    if(left < mdl)  quick_sort_strings(array, left, mdl - 1);
    if(right > mdl) quick_sort_strings(array, mdl + 1, right);
}

int str_cmp_4_sort_from_end(const char** str1, const char** str2){
    int i = 0, j = 0;
    while(TRUE){
        if(*str1[i] == '\0' || *str2[j] == '\0') break;
        ++i;
        ++j;
    }
    while(i >= 0 && j >= 0){
        if(!(isalpha(*str1[i]) || *str1[i] == '\0')) i--;
        if(!(isalpha(*str2[j]) || *str2[j] == '\0')) j--;

        if  (i < 0 && j < 0) return 0;
        else if(i < 0 || j < 0) return i - j;

        if(*str1[i] == *str2[j]){
            i--;
            j--;
        }
        else return *str1[i] - *str2[i];
    }
    return 0;
}


int str_cmp_4_sort(const char* str1, const char* str2){
    int i = 0, j = 0;
    while(TRUE){
        if(!(isalpha(str1[i]) || str1[i] == '\0')) i++;
        if(!(isalpha(str2[j]) || str2[j] == '\0')) j++;

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
        if(str1[i] == '\0' || str2[i] == '\0') return FALSE;
        return FALSE;
    }
}


int Compare(const void* str1, const void* str2){
    const char *new_str1 = *(const char**)str1;
    const char *new_str2 = *(const char**)str2;

    return strcmp(new_str1, new_str2);
}


#endif //ONEGIN_MYSTR_H
