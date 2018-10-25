/**\file main.cpp
 * the file that contains the main function 
 */ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unistd.h>
#include "PremiseChecker/PremiseChecker.h"
#include "AndElimination/AndElimin.h"
#include "AndIntroduction/AndIntro.h"
#include "ImplicationElimination/ImplicElimin.h"
#include "OrIntroduction/OrIntro.h"
#include "ModusTollens/ModusTollens.h"

using namespace std;
using namespace std::chrono;
/**
 * \fn main() 
 * \brief the main function of program
 * this function takes input of a proof of a given sequent
 * and checks whether the sequent is valid or not\n
 * it deals with inputs and outputs via stream
*/

int main() {
    //member variables
    static int n;// number of lines in proof
    cin>>n;// user enters no. of lines
    cin.ignore(numeric_limits<streamsize>::max(),'\n');


    vector <string> vec;
    for(int i=0;i<n;i++) {
        string s; //complete proof
        cin>>s;//user inputting complete proof
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        vec.push_back(s);
    }

    auto start=high_resolution_clock::now();// starting of clock to measure time 


    int slashCount[n];

    string statement[n];
    string rule[n];
    string linesUsedByRule[n];

    int line[n];
    int flag=0;
    for(int i=0;i<n;i++) {
        line[i]=0;
    }


 // we separate whole proof into different sections based on their function 
    for(int i=0;i<vec.size();i++) {

        slashCount[i] = count(vec[i].begin(), vec[i].end(), '/');
        unsigned first = vec[i].find_first_of('/');


        if (slashCount[i] > 1) {
            unsigned next = vec[i].find("/", first+1);
            int ruleLength=next-first-1;
            rule[i] = vec[i].substr(first+1, ruleLength);
            linesUsedByRule[i] = vec[i].substr(next+1, vec[i].length());
        } else if (slashCount[i] == 1) {
            rule[i] = vec[i].substr(first+1, vec[i].length());
        } else {
            cout << "Invalid Proof" << endl;
            return 0;
        }
    }
    
    for(int i=0;i<vec.size();i++) {
        unsigned first = vec[i].find_first_of('/');
        statement[i] = vec[i].substr(0, first);
    }

    for(int i=0;i<vec.size();i++) {
        //checks if statement[i] is a statement
        PremiseChecker pr(statement[i],rule[i]);
        if(pr.check()) {
            line[i]=1;
        }
        // if is not a statement then it is is a symbol 
        //based on which symbol it is, a different process is used. 
        if(rule[i]=="^i"){
            AndIntro andIn(linesUsedByRule[i],i);
            if(andIn.check(statement)) {
                line[i]=1;
            }
        }
        else if ((rule[i]=="^e1") || (rule[i]=="^e2")) {
            AndElimin andEl(rule[i],linesUsedByRule[i],i);
            if (andEl.check(statement)) {
                line[i]=1;
            }
        }
        else if((rule[i]=="Vi1") || (rule[i]=="Vi2")) {
            OrIntro orIn(rule[i],linesUsedByRule[i],i);
            if(orIn.check(statement)) {
                line[i]=1;
            }
        }
        else if(rule[i]==">e") {
            ImplicElimin implicEl(linesUsedByRule[i],i);
            if(implicEl.check(statement)) {
                line[i]=1;
            }
        }
        else if(rule[i]=="MT") {
            ModusTollens modusTollens(linesUsedByRule[i],i);
            if(modusTollens.check(statement)) {
                line[i]=1;
            }
        }

    }
    //checks if all statements can be validated  
    for(int i=0;i<n;i++) {
        if(line[i]==0) {
            flag++;
        }
    }



    //decide and declare if proof is valid or not
    if(flag==0) {
        cout<<"Valid Proof"<<endl;
    } else {
        cout<<"Invalid Proof"<<endl;

    }
    //stop clock and measure time taken
    auto stop = high_resolution_clock::now();
    

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Run Time is " << duration.count() << " microseconds" << endl;


    return 0;
}
