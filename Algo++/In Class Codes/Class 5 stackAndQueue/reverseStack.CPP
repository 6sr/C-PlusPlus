//Try reverse stack only with recursion
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q,int i,int j) {
    if(i == j || i == j - 1) {
        return;
    }
    int a = q.front();
    q.pop();
    reverseQueue(q,i + 1,j);
    q.push(a);
}

void reverseStack(stack<int> &s,int i,int j) {
    int a = s.top();
    s.pop();
    if(i == j) {
        s.push(a);
        return;
    }
    int b = s.top();
    s.pop();
    s.push(a);
    reverseStack(s,i + 1,j);
    s.push(b);
}

int main() {
    stack<int> s;
    int n;
    cin>>n;
    int i = 0,j = -1;
    while(n != -1) {
        j++;
        s.push(n);
        cin>>n;
    }
    for(int k = 0;k < j;k++) 
        reverseStack(s,i,j - k);
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}