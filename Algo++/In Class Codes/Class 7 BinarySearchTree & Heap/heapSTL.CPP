#include<iostream>
#include<queue>
using namespace std;

class Compare {
public :
    bool operator()(int a,int b) {
        return a < b;   //max heap
        //return a > b;   //min heap

        //Soting is inverse of this a < b means ascending order
    }
};

int main() {
    priority_queue<int> h;  //max heap
    priority_queue<int,vector<int>,greater<int>> h_min;     //min heap
    priority_queue<int,vector<int>,Compare> myHeap;
    int d;
    cin>>d;
    while(d != -1) {
        h.push(d);
        cin>>d;
    }
    while(!h.empty()) {
        cout<<h.top()<<"  ";        //a[i++] = h.top();     heap sort nlogn complexity
        //min heap sorts in ascending order
        //max heap sorts in descending order
        //in place heap sort
        h.pop();
    }
    return 0;
}
