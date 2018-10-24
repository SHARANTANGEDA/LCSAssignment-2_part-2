//
// Created by sharan on 24/10/18.
//

#ifndef ASSP2_MODUSTOLLENS_H
#define ASSP2_MODUSTOLLENS_H

#include <string>
using namespace std;

class ModusTollens {

    int linesused[2];
    int iteration;


public:
    ModusTollens(string param ,int i);
    bool check(string s[]);
};


#endif //ASSP2_MODUSTOLLENS_H
