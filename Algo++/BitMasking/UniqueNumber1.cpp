//We are given an array containg n numbers. All the numbers are present twice except for one number which is only present once. Find the
//unique number without taking any extra spaces and in linear time. ( Hint - Use Bitwise )

#include<iostream>
using namespace std;
int main() {
  int t,ans = 0,n;
  cin>>t;
  while(t--) {
    cin>>n;
    ans = ans ^ n;
  }
  cout<<ans;
	return 0;
}
