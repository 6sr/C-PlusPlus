//Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take 
//alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. 
//The value of coin is received by that player. Determine the maximum value that piyush can win if he moves first. Both the players
//play optimally.

#include<iostream>
#include<cmath>
using namespace std;

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

int main() {
  int n;
  cin>>n;
  int arr[n];
  int dp[100][100];
  for(int i = 0;i < n;i++) {
    cin>>arr[i];
  }
  cout<<winCoinPick(arr,0,n - 1,dp);
	return 0;
}
