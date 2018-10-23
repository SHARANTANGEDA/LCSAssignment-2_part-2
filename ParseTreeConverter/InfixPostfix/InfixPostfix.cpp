//
// Created by sharan on 22/10/18.
//

#include <stack>
#include <sstream>
#include <iostream>
#include "InfixPostfix.h"

using namespace std;

InfixPostfix::InfixPostfix(int len, char arr[]) {
    stack<char> s;
    stringstream post;
    for (int i = 0; i < len; i++) {
        if ((arr[i] != '~') && (arr[i] != 'V') && (arr[i] != '^') && (arr[i] != '>') && (arr[i] != ')') && (arr[i] != '(')) {
            post << arr[i];
        }

        if ((s.empty()) && ((arr[i] == '~') || (arr[i] == 'V') || (arr[i] == '^') || (arr[i] == '(') || (arr[i] == '>') || (arr[i] == ')'))) {
            s.push(arr[i]);
        }

        if(!(s.empty()) && ((arr[i] == '~') || (arr[i] == 'V') || (arr[i] == '^') || (arr[i] == '(') || (arr[i] == '>') || (arr[i] == ')')))  {
            if(arr[i]=='(') {
                s.push(arr[i]);
            }
            else if(arr[i]==')') {
                while (s.top()!='(') {
                    post<<s.top();
                    s.pop();
                }
                s.pop();
            }
            else  {
                while (precedence(s.top())>=precedence(arr[i])) {
                    post<<s.top();
                    s.pop();
                }
                s.push(arr[i]);
            }
        }
    }

    while (!s.empty()) {

        if ((s.top() != '(')) {
            post << s.top();
        }
        s.pop();
    }


    string print = post.str();
    postfix=print;

    cout << print << endl;
}

int InfixPostfix::precedence(char a) {
    switch (a) {

        case '~':
            return 4;
        case '^':
            return 3;
        case 'V':
            return 2;
        case '>':
            return 1;
        case '(':
            return 0;
    }
}

string InfixPostfix ::getPostFix() {
    return postfix;
}