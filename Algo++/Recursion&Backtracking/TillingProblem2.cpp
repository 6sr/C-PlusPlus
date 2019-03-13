//Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m .

#include<iostream>
using namespace std;

#define num 1000000007

unsigned long long tilling(int n,int m,unsigned long long *dp) {
  if(n < m) {
    return dp[n] = 1;
  }
  if(dp[n] != 0) {
    return dp[n];
  }
  dp[n] = (tilling(n - 1,m,dp) % num + tilling(n - m,m,dp) % num) % num;
  return dp[n];
}
int main() {
  int t,n,m;
  cin>>t;
  unsigned long long ans[t];
  for(int i = 0;i < t;i++) {
    unsigned long long dp[100000] = {0};
    cin>>n>>m;
    ans[i] = tilling(n,m,dp);
  }
  for(int i = 0;i < t;i++) {
    cout<<ans[i]<<endl;
  }
	return 0;
}
