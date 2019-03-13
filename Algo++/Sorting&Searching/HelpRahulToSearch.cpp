//Rahul had a sorted array of numbers from which he had to find a given number quickly. His friend by mistake rotated the array. 
//Now Rahul doesn't have time to sort the elements again. Help him to quickly find the given number from the rotated array.

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
      cout<<i;
      return 0;
    }
  }
  cout<<-1;
	return 0;
}
