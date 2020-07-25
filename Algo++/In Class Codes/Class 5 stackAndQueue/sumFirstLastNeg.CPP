#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> qMin;
    queue<int> qMax;
    int arr[] = {2,5,-1,7,-3,-1,-2};
    int n = sizeof(arr) / sizeof(int);
    int k;
    cin>>k;
    int i;
    
    for(i = 0;i < k;i++) {
        if(arr[i] < 0) {
            qMin.push(i);
        }
    }
    if(qMin.empty()) {
        cout<<0<<"  ";
    }
    else {
        cout<<arr[q.front()] + arr[q.back()]<<"  ";
    }

    for(;i < n;i++) {
        if(q.front() <= i - k && !q.empty()) {
            q.pop();
        }
        if(arr[i] < 0) {
            q.push(i);
        }
        if(q.empty()) {
            cout<<0<<"  ";
        }
        else {
            cout<<arr[q.front()] + arr[q.back()]<<"  ";
        }
    }
    return 0;
}