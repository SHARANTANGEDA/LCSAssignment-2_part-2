//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_ANDINTRO_H
#define ASSP2_ANDINTRO_H

#include <string>
using namespace std;


class AndIntro {

    string statement;
    string rule;
    int slash;
    int linesused[2];


public:
    AndIntro(string s,string r,string param, int sl);
    bool check();
};


#endif //ASSP2_ANDINTRO_H
