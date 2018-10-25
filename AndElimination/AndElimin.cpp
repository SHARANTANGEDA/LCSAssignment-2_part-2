//
// Created by sharan on 22/10/18.
//

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstring>
#include "AndElimin.h"
#include "../ParseTreeConverter/InfixPostfix/InfixPostfix.h"
#include "../ParseTreeConverter/PostfixParseTree/PostfixParseTree.h"
#include "../ParseTreeConverter/TreeInfix/TreeInfix.h"

using namespace std;
/**
 * @param r a string type parameter that represents the proof rule used 
 * @param lu a string type parameter that represents the lines used by the proof rule
 * @param i an integer that represents the iterator(which represents the line of proof that we are currently analyzing)\n
 * it converts  given input parameters lu and required part of r into integers and stores the values as method variables
*/
AndElimin::AndElimin(string r, string lu, int i) {
    string last = r.substr(2, 1);
    iteration = i;
    int a = stoi(last);
    num = a;
    linesUsed = stoi(lu);

}
/**
 * @param s  an array of string that represents the whole set of statements\n
 * checks whether used proof rule is properly justified or not\n
 * returns true if proof rule is applied correctly, else it returns false 
*/
bool AndElimin::check(string s[]) {

    //******In And Statement***************************************
    int len=s[linesUsed-1].length();
    char arr[len+1];

    strcpy(arr,s[linesUsed-1].c_str());

    InfixPostfix infixPostfix1(len,arr);
    string postfix=infixPostfix1.getPostFix();

    PostfixParseTree postfixParseTree1(postfix.length(),postfix);
    Node* parseTree=postfixParseTree1.getTree();

    TreeInfix treeInfix1(parseTree,num);
    string output=treeInfix1.getInfix();

    //*************************************************************


    //After Elimination********************************************
    int len2=s[iteration].length();
    char arr2[len2+1];
    strcpy(arr2,s[iteration].c_str());


    InfixPostfix infixPostfix2(len2,arr2);
    string postfix2=infixPostfix2.getPostFix();

    PostfixParseTree postfixParseTree2(postfix2.length(),postfix2);
    Node* parseTree2=postfixParseTree2.getTree();


    TreeInfix treeInfix2(parseTree2,0);
    string output2=treeInfix2.getInfix();
    //**************************************************************

    int x=output.compare(output2);

    return x==0;

}