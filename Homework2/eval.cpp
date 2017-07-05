#include <iostream>
#include <stack>
#include <string>
using namespace std;

void booleanOperandInStack(char ch, const bool value[]) {
    stack<bool> boolStack;
    boolStack.empty();
    
    for (int i = 0; i < 10; i++) {
        if  (ch == i) {
            boolStack.push(value[i]);
        }
    }
}

//check if operand is digit
bool isDigitOperand(char ch) {
    return isdigit(ch);
}






//ADDITIONAL FUNCTION

int precedence (char ch);
string inFixToPosFix(string& inFix);
bool testPostFix();

int evaluate(string infix, const bool values[], string& postfix, bool& result)
{
    return 0;
}

int precedence(char ch) {
    switch(ch) {
        case '|': //lowest precedence
            return 0;
            
        case '&': //second highest precedence
            return 1;
        
        case '!': //highest precedence
            return 2;
            
        default: //if no operators then return -1
            return -1;
            
    }
}

//IMPLIMENTAION OF ADDITIONAL FUNCTION


string inFixToPosFix(string& infix) {
    string postFix = ""; // initialize the empty string to postfix
    
    stack<char> operatorStack; //create a operator stack
    operatorStack.empty(); //initialize operator stack to empty
    
    for (int i =0; i < infix.size(); i++) { //getting each string character
        
        char ch = infix[i];
        if(isdigit(ch)) {
            postFix+= ch;
            continue;
        }
        
        
        switch(ch) {
            case '(': // if oepn paranthesis, push into the stack
                operatorStack.push(ch);
                break;
            
            case ')':
                while (operatorStack.top() != '(') { //untill match (
                    postFix += operatorStack.top(); //append stack top into postFix
                    operatorStack.pop(); //popping each time stack as loop goes
                }
                operatorStack.pop(); //pop stack to remove (
                break;
            
                //for the  3 operators
            case '!':
            case '&':
            case '|':
                //operator like !, &, |, append to profix
                while (!operatorStack.empty() && operatorStack.top() != '(' && precedence(ch)
                       <= precedence(operatorStack.top())) {
                    postFix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(ch); //push the operator on the stack
                while (!operatorStack.empty()) {
                    char temp = operatorStack.top();
                    operatorStack.pop();
                    if (temp == '(') {
                        operatorStack.push('(');
                        break;
                    } else {
                        
                    }
                }
                break;
            case ' ':
            break;
            default:
                break;
        }
    }
    while (!operatorStack.empty()) { //after everything append, and if anything left in stack
        postFix += operatorStack.top();//then stack to postfix
        operatorStack.pop();
    }
    return postFix;
    
}

bool testInfix(string &inFix) {
    if (inFix.size() == 0)
        return false;
    
    if (inFix[0] == ')' || inFix[0] == '&' || inFix[0] == '|' || inFix[0] == '+' || inFix[0] == '-' || inFix[0] == '*' || inFix[0] == '/')
        return false;
    
    if (inFix[inFix.size() -1] == '(' || inFix[inFix.size() -1] == '&' || inFix[inFix.size() -1] == '|' || inFix[inFix.size() -1] == '+' || inFix[inFix.size() -1] == '-' || inFix[inFix.size() -1] == '*' || inFix[inFix.size() -1] == '/')
        return false;
    
    return true;
}

bool isNumber(char character) {
    if (character >= 0 && character <=9)
        return true;
    else
        return false;
}

int main() {
    return 0;
}


























