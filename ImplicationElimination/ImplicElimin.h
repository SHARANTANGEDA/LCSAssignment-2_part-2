//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_IMPLICELIMIN_H
#define ASSP2_IMPLICELIMIN_H

#include <string>
using namespace std;


class ImplicElimin {
    int linesused[2];
    int iteration;


public:
    ImplicElimin(string lu,int i);
    bool check(string s[]);
};


#endif //ASSP2_IMPLICELIMIN_H
