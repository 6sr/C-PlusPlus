#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    int *arr;
    arr = new int [n];
    for(int i = 0;i < n;i++) {
        cin>>arr[i];
    }
    int m,idx,mid;
    cin>>m;

    //search(search(arr,arr + n,m);     -->linear search

    //arr should be sorted
    //binary_search(arr,arr + n,m);     --->boolean
    //lower_bound(arr,arr + n,m);       ---> same key 1st occ   //returns address
    //upper_bound(arr,arr + n,m);       --->just bigger idx     //returns address

    int lowerBound = lower_bound(arr,arr + n,m) - arr;
    int upperBound = upper_bound(arr,arr + n,m) - arr;

    int s = 0,e = n - 1;
    mid = (n - 1) / 2;
    while(s <= e) {
        if(arr[mid] == m) {
            idx = mid;
            //Calculating lower bound
            int currE = mid - 1;
            int currMid = (s + currE) / 2;
            while(arr[currMid] == m) {
                idx = currMid;
                currE = currMid - 1;
                currMid = (s + currE) / 2;
            }
            cout<<"LOWER : "<<idx;

            //Calculating upper bound
            currMid = (s + e) / 2;
            while(arr[currMid] == m) {
                idx = currMid;
               int currS = currMid + 1;
                currMid = (currS + e) / 2;
            }
            cout<<"UPPER : "<<idx<<endl;
            break;
        }
        if(arr[mid] > m) {
            e = mid - 1;
        }
        if(arr[mid] < m) {
            s = mid - 1;
        }
        mid = (s + e) / 2;
    }
    cout<<"LOL";
    return 0;
}

//Error
//8
//1 2 3 4 5 6 7 7
//7