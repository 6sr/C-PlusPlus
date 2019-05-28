//Manal
//Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets. He has to find whether if the 
//sum of any of the non-empty subsets of the set A is zero.

#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int i, int sum, bool notEmpty){
    // base case
    if(i==n){
        if(notEmpty)return false;
        if(sum==0)return true;
        return false;
    }

    // first call excluding 
    bool val1 = subsetSum(arr,n,i+1,sum, true);
    if(val1)return true;
    bool val2 = subsetSum(arr,n,i+1,sum+arr[i], false);
    return val2;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(subsetSum(arr, n, 0, 0, false))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
