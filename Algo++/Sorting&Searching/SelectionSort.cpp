#include<iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  long long arr[n];
  for(int i = 0;i < n;i++) {
    cin>>arr[i];
  }
  for(int i = 0;i < n;i++) {
    long long small = arr[i];
    int idx = i;
    for(int j = i + 1;j < n;j++) {
      if(arr[j] < small) {
        small = arr[j];
        idx = j;
      }
    }
    swap(arr[i],arr[idx]);
  }
  for(int i = 0;i < n;i++) {
    cout<<arr[i]<<endl;
  }
	return 0;
}
