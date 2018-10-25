//
// Created by sharan on 22/10/18.re
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include "TreeInfix.h"

/**
 * @param tree a pointer to root node of a parse tree (a binary tree)
*/
TreeInfix::TreeInfix(Node *tree,int val) {

    if(val==1) {
        Node *subTree=tree->right;
        traverseInOrder(subTree);
    }
    else if(val==2) {
        Node *subTree=tree->left;

        traverseInOrder(subTree);
    }
    else if(val==0) {
        traverseInOrder(tree);
    }

    infix=store.str();
}

//Recursively traverses through parse tree InOrder
void TreeInfix::traverseInOrder(Node *tree) {
    if(tree){

        traverseInOrder(tree->right);
        store<<tree->data;
        traverseInOrder(tree->left);
    }

}

/**
 * returns the infix representation of parse tree in string format 
*/

string TreeInfix ::getInfix() {
    return infix;
}