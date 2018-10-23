//
// Created by sharan on 22/10/18.
//

#include <string>
#include <cstring>
#include <stack>
#include <iostream>
#include "PostfixParseTree.h"
using namespace std;

PostfixParseTree ::PostfixParseTree(int len, string s) {
    char arr[len+1];
    strcpy(arr,s.c_str());
    Node *root;
    Node *b1,*b2;
    stack <Node *> stack1;

    for (int i = 0; i < len; i++) {
        if((arr[i]!='~')&&(arr[i]!='>')&&(arr[i]!='V')&&(arr[i]!='^')) {

            root=newBranch(arr[i]);
            stack1.push(root);
        }
        else if(arr[i]=='~') {

            root=newBranch(arr[i]);

            if(!stack1.empty()) {
                b1=stack1.top();
                stack1.pop();
            }




            root->left=b1;
            root->right = NULL;
            stack1.push(root);
        }
        else {

            root=newBranch(arr[i]);

            if(!stack1.empty()) {
                b1=stack1.top();
                stack1.pop();
            }

            if(!stack1.empty()){
                b2=stack1.top();
                stack1.pop();
            }


            root->left=b1;
            root->right=b2;
            stack1.push(root);
        }
    }


    root=stack1.top();
    stack1.pop();
    tree=root;
}




Node* PostfixParseTree::newBranch(char store) {
    Node* temp=new Node;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=store;
    return temp;
}


Node* PostfixParseTree::getTree() {
    return tree;
}