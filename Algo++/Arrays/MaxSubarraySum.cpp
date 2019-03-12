/*
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of 
numbers which has the largest sum.
For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.
i/p - 
2
4
1 2 3 4
3
-10 5 10
o/p - 
10
15
*/
#include<iostream>
using namespace std;

int main() {
  int n,t;
  cin>>t;
  while(t--) {
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++) {
      cin>>arr[i];
    }
    int cs = 0,ms = 0;
    for(int i = 0;i < n;i++) {
      cs += arr[i];
      if(cs < 0) {
        cs = 0;
      }
      ms = (ms > cs)?ms:cs;
    }
    cout<<ms<<endl;
  }
	return 0;
}
