#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>


using namespace std;

class Stack{
public:
    char* arr;
    int top;
    int size;

    Stack(int s){
        size = s;
        arr = new char[s];
        top = -1;
    }

    void push(char c){
        if(top < size - 1){
			arr[++top] = c;
		} 
    }

    char pop(){
        if(top >= 0) return arr[top--];
        return '\0';
    }

    char peek(){
        if(top >= 0) return arr[top];
        return '\0';
    }

    bool isEmpty(){
        return top == -1;
    }
};

bool isOperand(char c){
    return isalnum(c);
}

int precedence(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string reverseExpr(string expr){
    reverse(expr.begin(), expr.end());
    for(int i = 0; i < expr.size(); i++){
        if(expr[i] == '(') expr[i] = ')';
        else if(expr[i] == ')') expr[i] = '(';
    }
    return expr;
}

string infixToPrefix(string infix){
    infix = reverseExpr(infix);
    Stack s(infix.length());
    string prefix = "";

    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];
        if(isOperand(c)) prefix += c;
        else if(c == '(') s.push(c);
        else if(c == ')'){
            while(!s.isEmpty() && s.peek() != '(') prefix += s.pop();
            s.pop();
        }
        else if(isOperator(c)){
            while(!s.isEmpty() && precedence(s.peek()) > precedence(c)) prefix += s.pop();
            s.push(c);
        }
    }

    while(!s.isEmpty()) prefix += s.pop();
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int evaluatePrefix(string prefix){
    Stack s(prefix.length());
    for(int i = prefix.length() - 1; i >= 0; i--){
        char c = prefix[i];
        if(isdigit(c)) s.push(c - '0');
        else if(isOperator(c)){
            int a = s.pop();
            int b = s.pop();
            int res;
            switch(c){
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': res = pow(a, b); break;
            }
            s.push(res);
        }
    }
    return s.pop();
}

int main(){
    string infix;
    cin >> infix;
    string prefix = infixToPrefix(infix);
    cout << prefix << endl;

    bool numeric = all_of(infix.begin(), infix.end(), [](char c){ return isdigit(c) || isOperator(c) || c=='(' || c==')'; });
    if(numeric) cout << evaluatePrefix(prefix) << endl;

    return 0;
}
