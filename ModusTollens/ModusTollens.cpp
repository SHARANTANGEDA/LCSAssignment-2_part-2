//
// Created by sharan on 24/10/18.
//

#include <algorithm>
#include <sstream>
#include <cstring>
#include <iostream>
#include "ModusTollens.h"
#include "../ParseTreeConverter/InfixPostfix/InfixPostfix.h"
#include "../ParseTreeConverter/PostfixParseTree/PostfixParseTree.h"
#include "../ParseTreeConverter/TreeInfix/TreeInfix.h"


ModusTollens::ModusTollens(string param, int i) {
    int slashcount=count(param.begin(), param.end(), '/');
    unsigned first = param.find_first_of('/');


    string phelp[param.length()-slashcount];
    phelp[0]=param.substr(0,first);
    phelp[1]=param.substr(first+1,param.length());



    linesused[0]=stoi(phelp[0]);
    linesused[1]=stoi(phelp[1]);

    iteration=i;
}

bool ModusTollens::check(string s[]) {
    //**************implies segregation****************************
    int implength=s[linesused[0]-1].length();
    char impArr[implength+1];
    strcpy(impArr,s[linesused[0]-1].c_str());

    InfixPostfix infixPostfixImpl(implength,impArr);
    string postfix=infixPostfixImpl.getPostFix();

    PostfixParseTree postfixParseTreeImpl(postfix.length(),postfix);
    Node* parseTree=postfixParseTreeImpl.getTree();

    TreeInfix treeInfixleft(parseTree,1);
    string impLeft=treeInfixleft.getInfix();

    TreeInfix treeInfixright(parseTree,2);
    string impRight=treeInfixright.getInfix();
    //****************************************************************


    //**********************left part's premise version***************
    int lplength=s[linesused[1]-1].length();
    char pArr[lplength+1];
    strcpy(pArr,s[linesused[1]-1].c_str());

    InfixPostfix infixPostfixP(lplength,pArr);
    string postfixP=infixPostfixP.getPostFix();

    PostfixParseTree postfixParseTreeP(postfixP.length(),postfixP);
    Node* parseTreeP=postfixParseTreeP.getTree();

    TreeInfix treeInfixP(parseTreeP,0);
    string pRight=treeInfixP.getInfix();
    //****************************************************************


    //**********************final result version*********************
    int reslength=s[iteration].length();
    char resArr[reslength+1];
    strcpy(resArr,s[iteration].c_str());

    InfixPostfix infixPostfixRes(reslength,resArr);
    string postfixRes=infixPostfixRes.getPostFix();

    PostfixParseTree postfixParseTreeRes(postfixRes.length(),postfixRes);
    Node* parseTreeRes=postfixParseTreeRes.getTree();

    TreeInfix treeInfixRes(parseTreeRes,0);
    string res=treeInfixRes.getInfix();
    //****************************************************************

    stringstream impLeftNeg;
    impLeftNeg<<"~";
    impLeftNeg<<impLeft;
    string afterNegimpLeft=impLeftNeg.str();

    stringstream impRightNeg;
    impRightNeg<<"~";
    impRightNeg<<impRight;
    string afterNegimpRight=impRightNeg.str();


    cout<<"AfterNegimpLeft: "<<afterNegimpLeft<<" AfterNegimpRight: "<<afterNegimpRight<<endl;
    cout<<"pRight: "<<pRight<<" Res: "<<res<<endl;



    int c1=afterNegimpLeft.compare(res);
    int c2=afterNegimpRight.compare(pRight);

    return ((c1==0) && (c2==0));
}