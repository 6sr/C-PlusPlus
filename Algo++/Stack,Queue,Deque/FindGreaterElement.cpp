//We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. 
//To find the next greater number for element Ai , start from index i + i and go uptil the last index after which we start looking 
//for the greater number from the starting index of the array since array is circular.

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n],b[n];
  for(int i = 0;i < n;i++) {
    cin>>a[i];
    b[i] = a[i];
  }
  sort(a,a + n);
  for(int i = 0;i < n;i++) {
    int j = 0;
    while(j < n && b[i] >= a[j]) {
      j++;
    }
    if(j == n) {
      cout<<"-1 ";
    }
    else {
      cout<<a[j]<<" ";
    }
  }
	return 0;
}
