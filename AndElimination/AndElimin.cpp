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

AndElimin::AndElimin(string r, string lu, int i) {
    string last = r.substr(2, 1);
    iteration = i;
    int a = stoi(last);
    num = a;
    linesUsed = stoi(lu);

}

bool AndElimin::check(string s[]) {
//    stringstream str;

    //******In And Statement***************************************
    int len=s[linesUsed-1].length();
    char arr[len+1];
//    cout<<"premise: "<<s[linesUsed-1]<<endl;
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
//    cout<<"Conc: "<<s[iteration]<<endl;

    InfixPostfix infixPostfix2(len2,arr2);
    string postfix2=infixPostfix2.getPostFix();

    PostfixParseTree postfixParseTree2(postfix2.length(),postfix2);
    Node* parseTree2=postfixParseTree2.getTree();


    TreeInfix treeInfix2(parseTree2,0);
    string output2=treeInfix2.getInfix();
    //**************************************************************

//    cout<<"1: "<<output<<"  2: "<<output2<<endl;
    int x=output.compare(output2);

    return x==0;

}