#include <iostream>
using namespace std;

class Stack {
private:
    int *stackArray;
    int capacity;
    int top;

public:
    Stack(int size) {
        capacity = size;
        stackArray = new int[capacity];  
        top = -1; 
    }

    ~Stack() {
        delete[] stackArray;
    }


    void push(int item) {
        if (top == capacity - 1) {
            cout << "Stack Overflow. Cannot push " << item << " onto the stack." << endl;
        } else {
            stackArray[++top] = item;  
            cout << "Pushed " << item << " onto the stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. Cannot pop from the stack." << endl;
        } else {
            cout << "Popped " << stackArray[top--] << " from the stack." << endl;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return stackArray[top];
        } else {
            cout << "Stack is empty. Nothing to peek." << endl;
            return -1;  
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack contents: ";
            for (int i = 0; i <= top; ++i) {
                cout << stackArray[i] << " ";
            }
            cout << endl;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    return 0;
}
