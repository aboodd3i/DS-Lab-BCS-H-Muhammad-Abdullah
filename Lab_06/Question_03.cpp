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
        return ((rear + 1) % size == front);
    }

    void enqueue(char c){
        if(isFull()){
            cout << "Queue Overflow" << endl;
            return;
        }
        if(front == -1){
            front = 0;
            rear = 0;
            arr[rear] = c;
        }
        else{
            rear = (rear + 1) % size;
            arr[rear] = c;
        }
    }

    char dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow! Nothing to dequeue." << endl;
            return '\0';
        }
        char removed = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % size;
        }
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
        while(true){
            cout << arr[i] << endl;
            if(i == rear) break;
            i = (i + 1) % size;
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
    q.enqueue('D');
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue('E');
    q.enqueue('F');
    q.display();

    q.enqueue('G');

    return 0;
}
