//
// Created by sharan on 22/10/18.
//

#ifndef ASSP2_POSTFIXPARSETREE_H
#define ASSP2_POSTFIXPARSETREE_H

#include <string>

using namespace std;
///to create a binary tree
/**
 * we create a data structure ,Node, that points to
 * the node to its left and the node to its right\n
 * this is the fundamental building block of a tree 
*/
struct Node {
    char data; ///< value stored in node
    Node *left; ///<points to node in left branch 
    Node *right;///<points to node in right branch 
};


/// class named PostfixParseTree
/**
 * this class contains the methods that will be used to
 * convert a postfix expression to a parse tree
*/
class PostfixParseTree {
//<a member variable
   Node *tree;  /*a  pointer variable of type node*/
public:
///constructor of class
/**
 * @param len -an integer that is supposed to represent length of second parameter, a string 's'
 * @param s -a string that is supposed to be a formula in postfix representation 
*/
    PostfixParseTree(int len,string s);
///method of class that returns a Boolean value
/**
 *checks whether given input character is a symbol or not
 * (i.e'V', '>' ,^' )
 * @param a -a character that is supposed to be checked
 * */ 
    bool isSymbol(char a);
///method of class that returns a pointer to a node
/**
 * creates a pointer that points to a new node 
 * @param store  -a character that is stored in the newly created node
*/
    Node* newBranch(char store);
///method of class that returns a pointer to a node
/**
 * gets pointer to root node of binary tree(parse tree) and returns it.\n
 * it takes no no parameters.
*/
    Node* getTree();

};



#endif //ASSP2_POSTFIXPARSETREE_H
