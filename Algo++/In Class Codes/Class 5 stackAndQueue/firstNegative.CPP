#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    int arr[] = {-1,2,1,-2,3,2,-5};
    int n = sizeof(arr) / sizeof(int);
    int k;
    cin>>k;
    int i;
    
    for(i = 0;i < k;i++) {
        if(arr[i] < 0) {
            q.push(i);
        }
    }
    if(q.empty()) {
        cout<<0<<"  ";
    }
    else {
        cout<<arr[q.front()]<<"  ";
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
            cout<<arr[q.front()]<<"  ";
        }
    }


    /*
    int neg,negIdx = 0;
    for(int i = 0;i < n - k;i++) {
        if(arr[i] < 0) {
            neg = arr[i];
            if(i >= k) {
                for(int i = 0;i < i / k;i++) {
                    cout<<0<<"  ";
                }
            }
            for(int j = negIdx;j < i;j++) {
                cout<<neg<<"  ";
            }
            negIdx = i;
        }
    }
    */
    return 0;
}