//
// Created by sharan on 22/10/18.
//

#include "PremiseChecker.h"
using namespace std;

PremiseChecker::PremiseChecker(string s,string r) {
    premise=s;
    rule=r;
}

bool PremiseChecker::check() {
    char ch=rule[0];
    string str=premise;

    return (ch == 'p');

}