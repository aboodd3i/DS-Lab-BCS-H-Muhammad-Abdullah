#include<iostream>
using namespace std;

class Process{
public:
    int id;
    int priority;
    Process* next;

    Process(int i,int p){
        id = i;
        priority = p;
        next = nullptr;
    }
};

class Queue{
    Process* front;
    Process* rear;

public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int id,int priority){
        Process* p = new Process(id,priority);
        if(rear == nullptr){
            front = rear = p;
            return;
        }
        rear->next = p;
        rear = p;
    }

    Process* dequeue(){
        if(front == nullptr) return nullptr;
        Process* temp = front;
        front = front->next;
        if(front == nullptr) rear = nullptr;
        return temp;
    }

    bool isEmpty(){
        return front == nullptr;
    }

    void display(){
        cout << "Queue (Arrival Order): ";
        Process* temp = front;
        while(temp != nullptr){
            cout << "[ID:" << temp->id << ",P:" << temp->priority << "] ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Stack{
    Process** arr;
    int top;
    int capacity;

public:
    Stack(int size){
        capacity = size;
        arr = new Process*[capacity];
        top = -1;
    }

    void push(Process* p){
        if(top < capacity - 1) arr[++top] = p;
    }

    Process* pop(){
        if(top >= 0) return arr[top--];
        return nullptr;
    }

    bool isEmpty(){
        return top == -1;
    }

    void display(){
        cout << "Stack (Execution Order): ";
        for(int i = top; i >= 0; i--){
            cout << "[ID:" << arr[i]->id << ",P:" << arr[i]->priority << "] ";
        }
        cout << endl;
    }
};

int main(){
    Queue arrivalQueue;
    arrivalQueue.enqueue(1,2);
    arrivalQueue.enqueue(2,5);
    arrivalQueue.enqueue(3,1);
    arrivalQueue.enqueue(4,4);

    arrivalQueue.display();

    Stack executionStack(10);
    while(!arrivalQueue.isEmpty()){
        Process* p = arrivalQueue.dequeue();
        if(p->priority >= 3) executionStack.push(p);
        else cout << "Process ID " << p->id << " is low priority, delayed" << endl;
    }

    executionStack.display();

    cout << "Executing processes (LIFO):" << endl;
    while(!executionStack.isEmpty()){
        Process* p = executionStack.pop();
        cout << "Executing Process ID: " << p->id << ", Priority: " << p->priority << endl;
        delete p;
    }

    return 0;
}
