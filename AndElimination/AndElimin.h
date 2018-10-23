//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_ANDELIMIN_H
#define ASSP2_ANDELIMIN_H

#include <string>
using namespace std;

class AndElimin {
    int iteration;
    int num;
    int linesUsed;

public:
    AndElimin(string r,string lu,int i);
    bool check(string s[]);
};


#endif //ASSP2_ANDELIMIN_H
