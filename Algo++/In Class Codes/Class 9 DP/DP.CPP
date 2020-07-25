/*
optimiztion technique to optimize recursion problems
condition for applying dp
1. overlapping subproblems
2. optimal substructure
if 1 absent and 

=> Rec with memoization is top down dp      95% by this (try this first)
=> iterative is bottom up dp                if space complexity tight then this, 5% cases
*/
//segmentation fault -> out of bound index,memory short

#include<iostream>
#include<limits.h>      //For INT_MAX
using namespace std;

int min(int a,int b) {
    return (a > b)?b:a;
}

int max(int a,int b) {
    return (a < b)?b:a;
}

//Question 1
//Min num of ways to reach 1 from n by performing some operations on n
int reachOne(int n,int *dp) {
    if(dp[n] != -1) {
        return dp[n];
    }
    if(n == 1) {
        return 0;
    }
    int op1 = INT_MAX,op2 = INT_MAX,op3 = INT_MAX;
    if(n % 3 == 0) {
        op1 = reachOne(n / 3,dp);
    }
    if(n % 2 == 0) {
        op2 = reachOne(n / 2,dp);
    }
    op3 = reachOne(n - 1,dp);
    return dp[n] = (min(op1,min(op2,op3)) + 1);
}

//Question 2
//Get change of Rs. n
//no of coins should be min
int minCoinChange(int n,int *coin,int *dp) {
    if(dp[n] != -1) {
        return dp[n];
    }
    if(n == 0) {
        return 0;
    }
    int sizeCoin = sizeof(coin) / sizeof(int);
    int op[sizeof(coin) / sizeof(int)] = {INT_MAX};
    int ans = INT_MAX;
    for(int i = 0;i < sizeCoin;i++) {
        if(coin[i] <= n) {
            op[i] = minCoinChange(n - coin[i],coin,dp);
        }
        if(op[i] < ans) {
            ans = op[i];
        }
    }
    return dp[n] = ans + 1;
}

int minCoinBottomUp(int n,int *coin,int m) {
    int b[1000] = {0};

    for(int j = 1;j <= n;j++) {
        int ans = INT_MAX;
        for(int i = 0;i < m;i++) {
            if(j > coin[i]) {
                int subProb = b[j - coin[i]];
                int ans = min(ans, subProb + 1);
            }
        }
        b[j] = ans;
    }
    return b[n];
}

//Question 3
//Arr is price of wine in row sell each year one wine from row
//price each year is (year no) * initial price
int maxProfitWine(int *arr,int i,int j,int dp[][100],int year) {
    if(i == j) {
        return dp[i][j] = year * arr[i];
    }
    if(dp[i][j] != 0) {
        return dp[i][j];
    }
    //Sell first wine in curr year
    int op1 = maxProfitWine(arr,i + 1,j,dp,year + 1) + year * arr[i];
    //Sell last wine in curr year
    int op2 = maxProfitWine(arr,i,j - 1,dp,year + 1) + year * arr[j];
    return dp[i][j] = max(op1,op2);
}

//Question 4
//Anoop and jatin start picking coins from arr of value arr[i]
//Anoop starts, max value Anoop gets
int winCoinPick(int *arr,int i,int j,int dp[][100]) {
    if(i > j) {
        return 0;
    }
    if(dp[i][j] != 0) {
        return dp[i][j];
    }
    int call1 = winCoinPick(arr,i + 2,j,dp);
    int call2 = winCoinPick(arr,i + 1,j - 1,dp);
    int call3 = winCoinPick(arr,i,j - 2,dp);

    int op1 = min(call1,call2) + arr[i];
    int op2 = min(call2,call3) + arr[j];

    dp[i][j] = max(op1,op2);
    return  dp[i][j];
}

//Question 5
//Theif steals objects
//Has limit for bag of maxWt kg
//Quantity of every object is one
int maxTheft(int *price,int *wt,int i,int maxWt,int dp[][100]) {
    if(i == sizeof(price) / sizeof(int) || maxWt <= 0) {
        return 0;
    }
    int op1 = 0;
    if(wt[i] <= maxWt) {
        //Considering curr item
        op1 = maxTheft(price,wt,i + 1,maxWt - wt[i],dp) + price[i];
    }
    //Ignore curr item
    int op2 = maxTheft(price,wt,i + 1,maxWt,dp);
    return dp[i][maxWt] = max(op1,op2);
}
//Quantity inf
//  op1 = maxTheft(price,wt,i,maxWt - wt[i],dp) + price[i];
//  op2 = maxTheft(price,wt,i + 1,maxWt,dp) + price[i];

//Try bottom up for knapsack || maxTheft

int main() {
    int n;
    //int dp[100] = {0};
    int dp[100][100] = {0};     //Only for setting elements as zero not for any other value
    //cin>>n;
    int arr[] = {1,5,7,6,2,3,10,8};
    n = 8;
    //reachOne(n,dp);
    
    //int coin[] = {1,7,10};
    //cout<<minCoinChange(n,coin,dp);
    /*
    cout<<maxProfitWine(arr,0,n - 1,dp,1);
    cout<<endl;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    cout<<winCoinPick(arr,0,n - 1,dp);
    return 0;
}

//learn memset