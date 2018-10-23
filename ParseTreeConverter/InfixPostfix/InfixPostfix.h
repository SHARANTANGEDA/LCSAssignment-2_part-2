//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_INFIXPOSTFIX_H
#define ASSP2_INFIXPOSTFIX_H

#include <string>

using namespace std;

class InfixPostfix {
    string postfix;

public:
    InfixPostfix(int len, char arr[]);
    int precedence(char a);
    string getPostFix();

};


#endif //ASSP2_INFIXPOSTFIX_H
