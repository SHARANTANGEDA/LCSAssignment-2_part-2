//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_TREEINFIX_H
#define ASSP2_TREEINFIX_H


#include "../PostfixParseTree/PostfixParseTree.h"

#include <string>
#include <sstream>

class TreeInfix {
    string infix;
    stringstream store;
public:
    TreeInfix(Node *tree,int val);
    string getInfix();

    void traverseInOrder(Node *tree);
};


#endif //ASSP2_TREEINFIX_H
