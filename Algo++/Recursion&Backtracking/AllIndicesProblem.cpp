//Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive 
//function which returns an array containing indices of all items in the array which have value equal to M. Print all the values in 
//the returned array.

#include<iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0;i < n;i++) {
    cin>>arr[i];
  }
  int m;
  cin>>m;
  for(int i = 0;i < n;i++) {
    if(arr[i] == m) {
      cout<<i<<" ";
    }
  }
	return 0;
}
