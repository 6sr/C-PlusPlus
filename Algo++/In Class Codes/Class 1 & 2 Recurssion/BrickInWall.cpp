#include<iostream>
using namespace std;

int numWays(int n,int *dp) {
    if(n <= 3)
        return 1;
    if(dp[n] != 0) {
        return dp[n];
    }
    dp[n] = (numWays(n - 1,dp) + numWays(n - 4,dp));
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    int *dp;
    dp = new int[n]{0};
    cout<<numWays(n,dp);
    return 0;
}