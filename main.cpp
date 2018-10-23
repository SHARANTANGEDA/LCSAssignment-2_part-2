#include <iostream>
#include <vector>
#include <algorithm>
#include "PremiseChecker/PremiseChecker.h"
#include "AndElimination/AndElimin.h"
#include "AndIntroduction/AndIntro.h"
#include "ImplicationElimination/ImplicIntro.h"
#include "OrIntroduction/OrIntro.h"

using namespace std;

int main() {
    int n;
    cin>>n;
    vector <string> vec;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        vec.push_back(s);
    }

    vector <string> :: iterator it;
    int slashcount[n];
    string rule[n];
    string linesUsedByRule[n];
    int line[n];
    int flag=0;
    int verify=0;


    for(int i=0;i<n;i++) {

        slashcount[i] = count(vec[i].begin(), vec[i].end(), '/');
        unsigned first = vec[i].find_first_of('/');

        if (slashcount[i] > 1) {
            unsigned next = vec[i].find('/', first);
            rule[i] = vec[i].substr(first, next);
            linesUsedByRule[i] = vec[i].substr(next, vec[i].length());
        } else if (slashcount[i] == 1) {
            rule[i] = vec[i].substr(first, vec[i].length());
        } else {
            cout << "Invalid Proof" << endl;
            return 0;
        }
    }



    for(int i=0;i<vec.size();i++) {

        unsigned first = vec[i].find_first_of('/');
        string statement;
        statement = vec[i].substr(0, first);

        PremiseChecker pr(statement,rule[i]);
        if(pr.check()) {
            line[i]=1;
        }

        if(linesUsedByRule[i].length()==3){
            AndIntro andIn(statement,rule[i],linesUsedByRule[i],slashcount[i]);
            if(andIn.check()) {
                line[i]=1;
            }
        }

    }



    if(flag==0) {
        cout<<"Valid Proof"<<endl;
    } else {
        cout<<"Invalid Proof"<<endl;

    }


    return 0;
}