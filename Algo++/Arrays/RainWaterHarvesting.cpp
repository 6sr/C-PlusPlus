/*
Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Test Case
https://minio.codingblocks.com/img/ScHHWbX.jpg
So the total units of water she can save is 5 units
i/p - 
10
0 2 1 3 0 1 2 1 2 1
o/p - 5
*/
#include<iostream>
using namespace std;

int store = 0,n,last = 0;
void water(int s,int *arr) {
  if(s >= n - 1 || s > last) {
    return;
  }
  int end = s,max = 0;
  for(int i = s + 1;i < n;i++) {
    if(arr[i] >= arr[s]) {
      end = i;
      break;
    }
    if(max < arr[i]) {
      end = i;
      max = arr[i];
    }
  }
  int small = (arr[s] > arr[end])?end:s;
  for(int i = s + 1;i < end;i++) {
    store += arr[small] - arr[i];
  }
  int i = end;
  while(arr[i] <= arr[i + 1]) {
    if(i == n - 2) {
      return;
    }
    i++;
  }
  water(i,arr);
}

int main() {
  cin>>n;
  int *arr;
  arr = new int[n];
  for(int i = 0;i < n;i++) {
    cin>>arr[i];
  }
  for(int i = n - 1;i > 0;i--) {
    if(arr[i] > arr[i - 1]) {
      last = i;
      break;
    }
  }
  int i = 0;
  while(arr[i] <= arr[i + 1]) {
    if(i == n - 2) {
      cout<<0;
      return 0;
    }
    i++;
  }
  water(i,arr);
  cout<<store;
	return 0;
}
