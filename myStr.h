//
// Created by pawlo on 20.09.2020.
//
#pragma once
#ifndef ONEGIN_MYSTR_H
#define ONEGIN_MYSTR_H

#define TRUE 1
#define FALSE 0

#include <cstring>

int str_cmp(const char* str1, const char* str2);
int Compare(const void* str1, const void* str2);



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
