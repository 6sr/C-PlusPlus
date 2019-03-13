//Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive 
//function which returns the last index at which M is found in the array and -1 if M is not found anywhere. Print the value returned.

#include<iostream>
using namespace std;

int findIdx(int *a,int i,int m) {
  if(i == -1) {
    return -1;
  }
  if(a[i] == m) {
    return i;
  }
  return findIdx(a,i - 1,m);
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i = 0;i < n;i++) {
    cin>>a[i];
  }
  int m;
  cin>>m;
  int idx = findIdx(a,n - 1,m);
  cout<<idx;
	return 0;
}
