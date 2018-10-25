//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_IMPLICELIMIN_H
#define ASSP2_IMPLICELIMIN_H

#include <string>
using namespace std;

/// used to check validity of implication elimination
class ImplicElimin {
    int linesused[2];///<member variable that is an integer array it is used to store lines used for justification of implication elimination
    int iteration;/// an iterator


public:
    ImplicElimin(string lu,int i);///<construct or of class
    bool check(string s[]);///< method of class that returns a Boolean value
};


#endif //ASSP2_IMPLICELIMIN_H
