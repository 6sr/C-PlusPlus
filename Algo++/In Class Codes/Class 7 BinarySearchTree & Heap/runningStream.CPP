#include<iostream>
#include<queue>
using namespace std;

int main() {
    int k;
    int *arr;
    cin>>k;
    arr= new int[k];
    priority_queue<int> h;     //max heap
    int ele;
    cin>>ele;
    int i = 0;
    while(ele != 0) {
        int x = (i > k)?k:i;
        i++;
        if(ele == -1) {
            cout<<"\nK min elements : ";
            for(int j = 0;j < x;j++) {
                arr[j] = h.top();
                h.pop();
                cout<<arr[j]<<" ";
            }
            cout<<endl;
            for(int j = 0;j < x;j++) {
                h.push(arr[j]);
            }
            i--;
            cin>>ele;
            continue;
        }
        if(i <= k) {
            h.push(ele);                                        
        }
        else if(i != 1 && ele < h.top()) {
            h.pop();
            h.push(ele);
        }
        cin>>ele;
    }
    cout<<"LOL";
    return 0;

}