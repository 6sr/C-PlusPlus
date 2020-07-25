#include<iostream>
#include<vector>
using namespace std;

class Stack {
    vector<int> v;
    int min;
public :
    bool isEmpty() {
        return v.size() == 0;
    }
    void push(int x) {
        if(isEmpty()) {
            v.push_back(x);
            min = x;
            return;
        }
        if(min > x) {
            v.push_back(2 * x  - min);
            min = x;
        }
        else {
            v.push_back(x);
        }
    }
    void pop() {
        if(isEmpty()) {
            cout<<"Stack is empty";
            return;
        }
        if(min >= v.back()) {
            min = 2 * min - v.back();
        }
        v.pop_back();
    }
    int top() {
        if(min < v.back()) {
            return v.back();
        }
        return 2 * min - v.back();
    }
    int minima() {
        return min;
    }
};

int main() {
    int n;
    Stack s;

    cin>>n;
    s.push(n);

    cin>>n;
    s.push(n);

    cin>>n;
    s.push(n);

    cin>>n;
    s.push(n);

    cin>>n;
    s.push(n);

    cout<<"Minima : "<<s.minima();
    s.pop();
    cout<<"Minima : "<<s.minima();
    s.pop();
    cout<<"Minima : "<<s.minima();
    s.pop();
    cout<<"Minima : "<<s.minima();
    s.pop();
    cout<<"Minima : "<<s.minima();

    return 0;
}






/*
class Stack {
    vector<int> v;
    vector<int> min;
public :
    bool isEmpty() {
        return v.size() == 0 && min.size() == 0;
    }
    void push(int x) {
        if(isEmpty()) {
            v.push_back(x);
            min.push_back(x);
            return;
        }
        v.push_back(x);
        if(min[min.size() - 1] >= x) {
            min.push_back(x);
        }

    }
    void pop() {
        if(isEmpty()) {
            cout<<"Stack is empty";
            return;
        }
        if(min.back() == top()) {
            min.pop_back();
        }
        v.pop_back();
    }
    int top() {
        return v[v.size()  - 1];
    }
};

int main() {
    return 0;
}
*/




/*
struct node {
    int data;
    node * next;
};

class Stack {
public :
    node * top;
    Stack(int d) {
        top->data = d;
        top->next = NULL:
    }
    void push(int d) {
        if(top == NULL) {
            top->data = d;
            top->next = NULL;
        }
        node * temp = new Stack(d);
        temp->next = top;
        top = temp;
    }
    void push()
}
*/