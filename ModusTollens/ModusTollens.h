//
// Created by sharan on 24/10/18.
//

#ifndef ASSP2_MODUSTOLLENS_H
#define ASSP2_MODUSTOLLENS_H

#include <string>
using namespace std;
/// class used to check validity of modus tollens
class ModusTollens {

    int linesused[2];///<method variable used to store lines of proof which are used to justify use of modus tollens
    int iteration;///<method variable used as an iterator 


public:
    ModusTollens(string param ,int i);///<constructor of class
    bool check(string s[]);///<method of class that returns Boolean value
};


#endif //ASSP2_MODUSTOLLENS_H
