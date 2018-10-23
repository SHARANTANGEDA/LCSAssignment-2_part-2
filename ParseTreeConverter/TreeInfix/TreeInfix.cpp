//
// Created by sharan on 22/10/18.re
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include "TreeInfix.h"

TreeInfix::TreeInfix(Node *tree,int val) {
    cout<<"TreeInfix :"<<__LINE__;
    if(val==1) {
        cout<<"TreeInfix :"<<__LINE__;

        Node *subTree=tree->left;
        if(subTree){
            cout<<"TreeInfix :"<<__LINE__;
            char s=subTree->data;
            cout<<s<<endl;
        }

        traverseInOrder(subTree);
    } else if(val==2) {
        Node *subTree=tree->right;
        cout<<"TreeInfix :"<<__LINE__;
        traverseInOrder(subTree);
    } else if(val==0) {
        traverseInOrder(tree);
    }

    infix=store.str();
    cout<<infix<<" hello "<<val<<endl;
}

//Recursively traverses through parse tree InOrder
void TreeInfix::traverseInOrder(Node *tree) {
    if(tree){

        traverseInOrder(tree->right);
        store<<tree->data;
        cout<<tree->data<<" hh"<<endl;
        traverseInOrder(tree->left);
    }

}

string TreeInfix ::getInfix() {
    return infix;
}