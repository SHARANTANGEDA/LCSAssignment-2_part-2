//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_INFIXPOSTFIX_H
#define ASSP2_INFIXPOSTFIX_H

#include <string>

using namespace std;

///class named InfixPostfix
/**
 * this class contains methods used to
 * convert a formula given in infix notation to a formula represented in postfix 
*/
class InfixPostfix {
    string postfix; ///< member variable of class

public:
    InfixPostfix(int len, char arr[]); ///<constructor of class
    int precedence(char a);///<method declaration with return type int  
    string getPostFix();///< method declaration  with return type string
};


#endif //ASSP2_INFIXPOSTFIX_H
