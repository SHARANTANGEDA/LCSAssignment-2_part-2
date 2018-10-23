//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_ANDINTRO_H
#define ASSP2_ANDINTRO_H

#include <string>
using namespace std;


class AndIntro {


    string rule;
    int slash;
    int linesused[2];
    int iteration;


public:

    AndIntro(string param,int i);

    bool check(string s[]);
};


#endif //ASSP2_ANDINTRO_H
