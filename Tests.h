//
// Created by pawlo on 20.09.2020.
//
#pragma once
#ifndef ONEGIN_TESTS_H
#define ONEGIN_TESTS_H

#include <cassert>
#include "myStr.h"

void AllTests();
void strcmp_Test();


void AllTests(){
    strcmp_Test();
    fprintf(stderr, "All tests are OK!\n");
}

void strcmp_Test(){
    const char* uno = "Milk";
    const char* dos = "Milk";
    const char* trs = "NotMilk";
    const char* qdr = "";
    const char* cnc = "";
    const char* sis = "Filk";
    const char* sit = "Z";
    const char* och = "z";
    const char* nve = "Milk ";

    assert( str_cmp(uno, dos));
    assert(!str_cmp(uno, trs));
    assert( str_cmp(qdr, cnc));
    assert(!str_cmp(uno, sis));
    assert(!str_cmp(uno, qdr));
    assert(!str_cmp(sit, och));
    assert(!str_cmp(uno, nve));
    fprintf(stderr, "Test str_cmp function is OK!\n");
}



#endif //ONEGIN_TESTS_H
