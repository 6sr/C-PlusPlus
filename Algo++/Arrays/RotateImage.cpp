//Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.
#include<iostream>
using namespace std;
int main() {
  int n;
  cin>>n;
  int arr[n][n];
  for(int i = 0;i < n;i++) {
    for(int j = 0;j < n;j++) {
      cin>>arr[i][j];
    }
  }
  for(int i = n - 1;i >= 0;i--) {
    for(int j = 0;j < n;j++) {
      cout<<arr[j][i]<<" ";
    }
    cout<<endl;
  }
	return 0;
}
