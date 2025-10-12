#include<iostream>
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
        if(top < size) arr[++top] = c;
    }

    char pop(){
        if(top > -1) return arr[top--];
        return '\0';
    }

    char peek(){
        if(top > -1) return arr[top];
        return '\0';
    }

    bool isEmpty(){
        return top == -1;
    }
};

bool isAlphanumeric(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
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

string infixToPostfix(string infix){
    Stack st(infix.length());
    string postfix = "";

    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];
        if(isAlphanumeric(c)) postfix += c;
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while(!st.isEmpty() && st.peek() != '(') postfix += st.pop();
            st.pop();
        }
        else if(isOperator(c)){
            while(!st.isEmpty() && precedence(st.peek()) >= precedence(c) && c != '^') postfix += st.pop();
            st.push(c);
        }
    }

    while(!st.isEmpty()) postfix += st.pop();

    cout << "Final Postfix Expression: " << postfix << endl;
    return postfix;
}

int evaluatePostfix(string postfix){
    Stack s(postfix.length());

    for(int i = 0; i < postfix.length(); i++){
        char c = postfix[i];
        if(isdigit(c)) s.push(c - '0');
        else if(isOperator(c)){
            int val2 = s.pop();
            int val1 = s.pop();
            int result;
            switch(c){
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
            }
            s.push(result);
        }
    }

    return s.pop();
}

int main(){
    string pf = infixToPostfix("(A+B*C)");
    cout << "Postfix Expression: " << pf << endl;
    return 0;
}
