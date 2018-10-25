//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_ANDINTRO_H
#define ASSP2_ANDINTRO_H

#include <string>



using namespace std;

///used to check validity of and introduction proof rule.
class AndIntro {

    int linesused[2];///<method variable used to store lines used for applying proof rule variables used
    int iteration;///<method variable used as an iterator


public:

    AndIntro(string param,int i);///<constructor of class
    bool check(string s[]);///<method of class that returns a Boolean value
};


#endif //ASSP2_ANDINTRO_H
