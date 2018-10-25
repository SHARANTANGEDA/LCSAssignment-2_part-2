//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_ORINTRO_H
#define ASSP2_ORINTRO_H

#include <string>
using namespace std;
//used to verify if or introduction which has been used can be properly verified 
class OrIntro {

    int iteration;///< an iterator 
    int num;///< a method variable of int type
    int linesUsed;///<the line used to prove or introduction

public:
    OrIntro(string r,string lu, int i);///<constructor of class
    bool check(string s[]);///<method of class that returns a Boolean value
};


#endif //ASSP2_ORINTRO_H
