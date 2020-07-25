#include<iostream>
using namespace std;

int ways(int n,int k) {
    //Base case
    if(n < 0) {
        return 0;
    }
    if(n == 1 || n == 0) {
        return 1;
    }
    //Rec case
    int ans = 0;
    for(int i = 1;i <= k;i++) {
        ans += ways(n - i,k);
    }
    return ans;
}

int main() {
    int n = 3,k = 2;
    cin>>n>>k;
    cout<<"No of ways of reaching nth step : "<<ways(n,k);
    return 0;
}