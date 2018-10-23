//
// Created by sharan on 22/10/18.
//

#include <sstream>
#include "AndIntro.h"
using namespace std;

AndIntro::AndIntro(string param ,int i) {



    linesused[0]=(int)param[0];
    linesused[1]=(int)param[2];

    iteration=i;

}

bool AndIntro::check(string s[]) {
    stringstream checker;
    checker<<s[linesused[0]-1];
    checker<<"^";
    checker<<s[linesused[1]-1];
    string ch=checker.str();

    int x=ch.compare(s[iteration]);

    return x == 0;

}