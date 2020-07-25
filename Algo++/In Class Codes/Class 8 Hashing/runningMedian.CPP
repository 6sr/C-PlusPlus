#include<iostream>
#include<queue>
using namespace std;

int main() {
    int k;
    int *arr;
    cin>>k;
    arr= new int[k];
    priority_queue<int> hMax;     //max heap
    priority_queue<int,vector<int>,greater<int>> hMin;
    int ele,med;
    cin>>ele;
    if(ele != -1) {
        med = ele;
    }
    int iMin = 0,iMax = 0;
    while(ele != 0) {
        if(ele == -1) {
            cout<<"Median : "<<med<<endl;
            cin>>ele;
            continue;
        }


        cin>>ele;
    }
    cout<<"LOL";
    return 0;
}