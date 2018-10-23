//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_PREMISE_H
#define ASSP2_PREMISE_H

#include <string>
using namespace std;

class PremiseChecker {

    string premise;
    string rule;
public:
    PremiseChecker(string s,string r);
    bool check();
};


#endif //ASSP2_PREMISE_H
