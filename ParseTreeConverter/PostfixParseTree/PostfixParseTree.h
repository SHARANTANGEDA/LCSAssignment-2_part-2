//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_POSTFIXPARSETREE_H
#define ASSP2_POSTFIXPARSETREE_H

#include <string>

using namespace std;
struct Node {
    char data;
    Node *left;
    Node *right;
};



class PostfixParseTree {


    Node *tree;
public:
    PostfixParseTree(int len,string s);

    Node* newBranch(char store);
    Node* getTree();

};


#endif //ASSP2_POSTFIXPARSETREE_H
