#include<iostream>
using namespace std;

int search(int *a,int low,int up,int num) {
  int mid;
  while(low <= up) {
    mid = (low + up) / 2;
    if(a[mid] == num) {
      return mid;
    }
    if(a[mid] > num) {
      up = mid - 1;
    }
    if(a[mid] < num) {
      low = mid + 1;
    }
  }
  return -1;
}
int main() {
  int n,m;
  cin>>n;
  int arr[n];
  for(int i = 0;i < n;i++) {
    cin>>arr[i];
  }
  cin>>m;
  cout<<search(arr,0,n - 1,m);
	return 0;
}
