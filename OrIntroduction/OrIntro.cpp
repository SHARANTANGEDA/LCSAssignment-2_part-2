//
// Created by sharan on 22/10/18.
//

#include <cstring>
#include "OrIntro.h"
#include "../ParseTreeConverter/InfixPostfix/InfixPostfix.h"
#include "../ParseTreeConverter/PostfixParseTree/PostfixParseTree.h"
#include "../ParseTreeConverter/TreeInfix/TreeInfix.h"

/**
 * @param r a string that represents the rule used
 * @param lu a string that mentions the lines of proof used for or introduction\n
 * the member variables are initialized 
*/
OrIntro::OrIntro(string r, string lu, int i) {
    string last = r.substr(2, 1);
    iteration = i;
    int a = stoi(last);
    num = a;
    linesUsed = stoi(lu);
}
/**
  * @param s  an array of strings that represents the whole set of statements\n
  * checks whether usage of or introduction is correctly justified
  * if it is, it returns true, else, it  returns false  
*/
bool OrIntro::check(string s[]) {

    //******In premise Statement***********************************
    int len=s[linesUsed-1].length();
    char arr[len+1];

    strcpy(arr,s[linesUsed-1].c_str());

    InfixPostfix infixPostfix1(len,arr);
    string postfix=infixPostfix1.getPostFix();

    PostfixParseTree postfixParseTree1(postfix.length(),postfix);
    Node* parseTree=postfixParseTree1.getTree();

    TreeInfix treeInfix1(parseTree,0);
    string output=treeInfix1.getInfix();

    //*************************************************************

    //After Or Introduction*****************************************
    int len2=s[iteration].length();
    char arr2[len2+1];
    strcpy(arr2,s[iteration].c_str());


    InfixPostfix infixPostfix2(len2,arr2);
    string postfix2=infixPostfix2.getPostFix();

    PostfixParseTree postfixParseTree2(postfix2.length(),postfix2);
    Node* parseTree2=postfixParseTree2.getTree();


    TreeInfix treeInfix2(parseTree2,num);
    string output2=treeInfix2.getInfix();
    //**************************************************************
    int x=output.compare(output2);

    return x==0;
}