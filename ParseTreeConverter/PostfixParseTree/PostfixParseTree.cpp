//
// Created by sharan on 22/10/18.
//

#include <string>
#include <cstring>
#include <stack>
#include <iostream>
#include "PostfixParseTree.h"
using namespace std;

/**
 * 
 * we traverse through the string inputted.
 * And generate a binary tree(parse tree) whose root node is pointed to by a member variable.
 * note: to get binary tree node pointer use getTree()
*/
PostfixParseTree ::PostfixParseTree(int len, string s) {
    // defining variables to help in generation of parse tree
    char arr[len+1];
    strcpy(arr,s.c_str());
    Node *root;  
    Node *b1,*b2;
    stack <Node *> stack1;
    // we iterate through the string 's' and based on value of s[i] act accordingly
    for (int i = 0; i < len; i++) {
        if((arr[i]!='~')&&(arr[i]!='>')&&(arr[i]!='V')&&(arr[i]!='^')) {       //if s[i]  is not a symbol 
            root=newBranch(arr[i]);
            stack1.push(root);
        }
        else if(arr[i]=='~') {                  // if s[i] is a negation symbol ('~')

            root=newBranch(arr[i]);

            if(!stack1.empty()) {
                b1=stack1.top();
                stack1.pop();
            }




            root->left=b1;
            root->right = NULL;
            stack1.push(root);
        }
        else if(isSymbol(arr[i])){         // if s[i] is any other symbol 
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
    tree=root;     //tree (member variable) is assigned to location of root of binary tree
}

bool PostfixParseTree ::isSymbol(char a) {
    return ((a == 'V') || (a == '^') || (a == '>'));

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