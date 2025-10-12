// Muhammad Saad Sohail      24K-0549

#include<iostream>
using namespace std;

class Queue{
    int size;
    char* arr;
    int front;
    int rear;

public:
    Queue(int s){
        arr = new char[s];
        size = s;
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return rear == size - 1;
    }

    void enqueue(char c){
        if(isFull()){
            cout << "Queue Overflow" << endl;
            return;
        }
        if(front == -1) front = 0;
        rear++;
        arr[rear] = c;
    }

    char dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow! Nothing to dequeue." << endl;
            return '\0';
        }
        char removed = arr[front];
        if(front == rear) front = rear = -1;
        else front++;
        cout << "Dequeued: " << removed << endl;
        return removed;
    }

    bool isEmpty(){
        return front == -1;
    }

    char peek(){
        if(!isEmpty()) return arr[rear];
        return '\0';
    }

    void display(){
        cout << "Queue elements:" << endl;
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while(i <= rear){
            cout << arr[i] << endl;
            i++;
        }
    }

    ~Queue(){
        delete[] arr;
    }
};

int main(){
    Queue q(5);

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    q.display();

    q.dequeue();
    q.display();

    q.enqueue('D');
    q.enqueue('E');
    q.enqueue('F');

    q.display();

    return 0;
}
