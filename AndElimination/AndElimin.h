//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_ANDELIMIN_H
#define ASSP2_ANDELIMIN_H

#include <string>
using namespace std;
/// used to check validity of and elimination
class AndElimin {
    int iteration;///<an iterator
    int num;  ///<an integer type method variable
    int linesUsed;///<an integer type method variable 

public:
    AndElimin(string r,string lu,int i);///<constructor of class
    bool check(string s[]);///<method of class that returns Boolean value
};


#endif //ASSP2_ANDELIMIN_H
