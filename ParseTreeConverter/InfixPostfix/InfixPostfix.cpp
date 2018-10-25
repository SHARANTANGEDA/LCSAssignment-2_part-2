//
// Created by sharan on 22/10/18.
//

#include <stack>
#include <sstream>
#include <iostream>
#include "InfixPostfix.h"

using namespace std;


/**
 * @param len - integer representing length of second input parameter of constructor (a character string)
 * @param arr  - a character array that represents a logic formula
*/
InfixPostfix::InfixPostfix(int len, char arr[]) 
{
    stack<char> s; //<creating a character stack 's'
    stringstream post; //<creating a stringstream  called post
    //iterating through the character array 'arr[]'
    for (int i = 0; i < len; i++) {
        /*if 'i'th element of 'arr[]' is not an operator symbol 
          then append 'arr[i]'  to post*/
        if ((arr[i] != '~') && (arr[i] != 'V') && (arr[i] != '^') && (arr[i] != '>') && (arr[i] != ')') && (arr[i] != '(')) {   
            post << arr[i]; 
        }
        /*if stack 's' is empty and 'i'th element of 'arr[]' is an operator
          push 'arr[i]' onto top of stack s */
        if ((s.empty()) && ((arr[i] == '~') || (arr[i] == 'V') || (arr[i] == '^') || (arr[i] == '(') || (arr[i] == '>') || (arr[i] == ')'))) {
            s.push(arr[i]);
        }
        //if stack 's' is not empty and 'i'th element of 'arr[]' is an operator we proceed based on type of operator
        if(!(s.empty()) && ((arr[i] == '~') || (arr[i] == 'V') || (arr[i] == '^') || (arr[i] == '(') || (arr[i] == '>') || (arr[i] == ')')))  {
            /* if 'arr[i]' is '('
            push 'arr[i]' onto top of stack s*/  
            if(arr[i]=='(') {
                s.push(arr[i]);
            }
            /*else if 'arr[i]' is ')' 
            */
            else if(arr[i]==')') {
                /*traverse down the stack s 
                 * by appending top most element to 'post' and then 'pop'ing stack
                 * until we reach a '('
                 */
                while (s.top()!='(') {
                    post<<s.top();
                    s.pop();
                }
            // then remove '(' from top of stack
                s.pop();
            }
            //if arr[i] is any other operator
            else  {
                /*we traverse down the stack s
                 * by appending top most element of stack to 'post' and then 'pop'ing  stack 's'
                 * until precedence of top of stack is less than precedence of 'arr[i]' (function for precedence is is defined later )
                */
                while (precedence(s.top())>=precedence(arr[i])) {
                    post<<s.top();
                    s.pop();
                }
                // then push arr[i] to top of stack
                s.push(arr[i]);
            }
        }
    }
    /*After completion of above loop
     * append the topmost element of stack 's' to 'post'
     * until stack is empty
    */
    while (!s.empty()) {

        if ((s.top() != '(')) {
            post << s.top();
        }
        s.pop();
    }


    string print = post.str(); //creating a variable 'string' that is assigned to the string stored in the stringstream 'post'.  
    postfix=print; //assigning print to instance variable postfix; 

   // cout << "PostFix is: "<<print << endl; //<printing the required post fix value
}


/**
 * @param a -where a is character representing a symbol\n
 *  (i.e '~', '(', 'V', '^', '>')
 * a five case switch where for each different symbol a different precedence value is returned
*/
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
/**
 * returns postfix representation of initially given infix formula in the form of a string 
*/
string InfixPostfix ::getPostFix() {
    return postfix;
}