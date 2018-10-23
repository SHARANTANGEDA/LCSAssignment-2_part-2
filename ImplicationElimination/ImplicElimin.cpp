//
// Created by sharan on 22/10/18.
//

#include <algorithm>
#include <cstring>
#include <iostream>
#include "ImplicElimin.h"
#include "../ParseTreeConverter/InfixPostfix/InfixPostfix.h"
#include "../ParseTreeConverter/PostfixParseTree/PostfixParseTree.h"
#include "../ParseTreeConverter/TreeInfix/TreeInfix.h"

ImplicElimin::ImplicElimin(string lu, int i) {
    int slashcount=count(lu.begin(), lu.end(), '/');
    unsigned first = lu.find_first_of('/');


    string phelp[lu.length()-slashcount];
    phelp[0]=lu.substr(0,first);
    phelp[1]=lu.substr(first+1,lu.length());




    linesused[0]=stoi(phelp[0]);
    linesused[1]=stoi(phelp[1]);

    cout<<linesused[0]<<"   "<<linesused[1]<<endl;

    iteration=i;
}

bool ImplicElimin::check(string s[]) {

    //**************implies segregation****************************
    int implength=s[linesused[0]-1].length();
    char impArr[implength+1];
    strcpy(impArr,s[linesused[0]-1].c_str());

    InfixPostfix infixPostfixImpl(implength,impArr);
    string postfix=infixPostfixImpl.getPostFix();

    PostfixParseTree postfixParseTreeImpl(postfix.length(),postfix);
    Node* parseTree=postfixParseTreeImpl.getTree();

    TreeInfix treeInfixleft(parseTree,1);
    string impleft=treeInfixleft.getInfix();

    TreeInfix treeInfixright(parseTree,2);
    string impright=treeInfixright.getInfix();
    //****************************************************************


    //**********************left part's premise version***************
    int lplength=s[linesused[1]-1].length();
    char pArr[lplength+1];
    strcpy(pArr,s[linesused[1]-1].c_str());

    InfixPostfix infixPostfixP(lplength,pArr);
    string postfix1=infixPostfixP.getPostFix();

    PostfixParseTree postfixParseTreeP(postfix1.length(),postfix1);
    Node* parseTree1=postfixParseTreeP.getTree();

    TreeInfix treeInfixP(parseTree1,0);
    string pLeft=treeInfixP.getInfix();
    //****************************************************************


    //**********************left part's premise version***************
    int reslength=s[iteration].length();
    char resArr[reslength+1];
    strcpy(resArr,s[iteration].c_str());

    InfixPostfix infixPostfixRes(reslength,resArr);
    string postfixRes=infixPostfixRes.getPostFix();

    PostfixParseTree postfixParseTreeRes(postfixRes.length(),postfixRes);
    Node* parseTreeRes=postfixParseTreeRes.getTree();

    TreeInfix treeInfixRes(parseTreeRes,0);
    string res=treeInfixP.getInfix();
    //****************************************************************

    int c1=impleft.compare(pLeft);
    int c2=impright.compare(res);

    return ((c1 == 0) && (c2 == 0));


}