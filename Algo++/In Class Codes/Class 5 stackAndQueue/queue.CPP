#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int cs;
    int ms;
    int front;
    int rear;
public :
    Queue(int size = 4) {
        cs = 0;
        ms = size;
        front = 0;
        rear = ms - 1;
        arr = new int[size];
    }
    bool isFull() {
        return (cs == ms);
    }
    bool isEmpty() {
        return !cs;
    }
    int getFront() {
        return arr[front];
    }
    int getBack() {
        return arr[rear];
    }
    void enqueue(int x) {
        if(isFull()) {
            cout<<"Queue is full";
            return;
        }
        rear = (rear + 1) % ms;
        arr[rear] = x;
        cs++;
    }
    void dequeue() {
        if(isEmpty()) {
            cout<<"Queue is empty";
            return;
        }
        front = (front + 1) % ms;
        cs--;
    }
};

int main() {
    Queue q(6);
    int n;

    cin>>n;
    q.enqueue(n);
    cin>>n;
    q.enqueue(n);
    cin>>n;
    q.enqueue(n);
    cin>>n;
    q.enqueue(n);
    cin>>n;
    q.enqueue(n);
    cout<<q.getFront()<<"  "<<q.getBack()<<endl;

    q.dequeue();
    cout<<q.getFront()<<"  "<<q.getBack()<<endl;
    q.dequeue();
    cout<<q.getFront()<<"  "<<q.getBack()<<endl;
    return 0;
}