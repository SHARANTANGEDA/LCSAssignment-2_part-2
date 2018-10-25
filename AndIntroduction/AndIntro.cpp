//
// Created by sharan on 22/10/18.
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include "AndIntro.h"
using namespace std;
/**
 * @param param  is a string array that contains the lines of proof used by and introduction proof rule  
 * @param i is an integer used to mention the line where and introduction is used
 * it divides param into different integer values each with a distinct line used for proving an introduction. 
*/
AndIntro::AndIntro(string param ,int i) {

    int slashcount=count(param.begin(), param.end(), '/');
    unsigned first = param.find_first_of('/');


    string phelp[param.length()-slashcount];
    phelp[0]=param.substr(0,first);
    phelp[1]=param.substr(first+1,param.length());



    linesused[0]=stoi(phelp[0]);
    linesused[1]=stoi(phelp[1]);

    iteration=i;


}
/**
 * @param s a string array that contains all the statements of proof 
 * checks whether or not 'and introduction' proof rule was used correctly\n
 * if it finds correct usage it returns true else it returns false 
*/
bool AndIntro::check(string s[]) {
    stringstream checker;
    checker<<"(";
    checker<<s[linesused[0]-1];
    checker<<"^";
    checker<<s[linesused[1]-1];
    checker<<")";

    string ch=checker.str();
    int x=ch.compare(s[iteration]);

    return x == 0;

}