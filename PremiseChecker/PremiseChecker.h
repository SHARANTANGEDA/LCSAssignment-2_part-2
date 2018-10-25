//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_PREMISE_H
#define ASSP2_PREMISE_H

#include <string>
using namespace std;

class PremiseChecker {

    string premise;///<member variable that stores premise 
    string rule;/// member variable that stores the rule of given line of statement
public:
    PremiseChecker(string s,string r);/// constructor of class
    bool check();/// method of class that returns Boolean value
};


#endif //ASSP2_PREMISE_H
