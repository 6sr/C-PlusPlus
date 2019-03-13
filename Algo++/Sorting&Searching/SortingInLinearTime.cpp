#include<iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  int arr[n];
  int s = 0,m = 0,e = n - 1;
  for(int i = 0;i < n;i++) {
    cin>>arr[i];
  }
while(m < e) {
    if(arr[m] == 0) {
      swap(arr[s],arr[m]);
      m++;
      s++;
    }
    if(arr[m] == 1) {
      m++;
    }
    if(arr[m] == 2) {
      swap(arr[m],arr[e]);
      e--;
    }
  }
  for(int i = 0;i < n;i++) {
    cout<<arr[i]<<endl;
  }
	return 0;
}
