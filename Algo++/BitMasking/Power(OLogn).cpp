//Take as input x and n, two numbers. Write a function to calculate x raise to power n. Target complexity is O(logn).
//NOTE: Try both recursive and bitmasking approach.

#include<iostream>
using namespace std;

int power(int x,int n) {
  if(x == 0) {
    return 0;
  }
  if(n == 0) {
    return 1;
  }
  if(n == 1) {
    return x;
  }
  int ans = power(x,n / 2);
  ans = ans * ans;
  if(n % 2 == 0) {
    return ans;
  }
  else {
    return x * ans;
  }
}
int main() {
  int x,n;
  cin>>x>>n;
  cout<<power(x,n);
	return 0;
}
