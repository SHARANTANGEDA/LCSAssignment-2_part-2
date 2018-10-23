//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_ORINTRO_H
#define ASSP2_ORINTRO_H

#include <string>
using namespace std;
class OrIntro {

    int iteration;
    int num;
    int linesUsed;

public:
    OrIntro(string r,string lu, int i);
    bool check(string s[]);
};


#endif //ASSP2_ORINTRO_H
