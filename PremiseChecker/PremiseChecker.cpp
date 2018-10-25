//
// Created by sharan on 22/10/18.
//

#include "PremiseChecker.h"
using namespace std;
/**
 * @param a string that represents a statement in the proof of a sequent
 * @param a string that stores the rule used in the same line as statement in above line
 * it initializes member variables
*/
PremiseChecker::PremiseChecker(string s,string r) {
    premise=s;
    rule=r;
}
/**
 * checks whether given statement is premise or not 
 * if yes , returns true , if no, returns false
*/
bool PremiseChecker::check() {
    char ch=rule[0];
    string str=premise;

    return (ch == 'P');

}