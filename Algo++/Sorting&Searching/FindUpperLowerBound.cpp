#include<iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0;i < n;i++) {
    cin>>arr[i];
  }
  int t,m;
  cin>>t;
  for(int i = 0;i < t;i++) {
    cin>>m;
    int lower = -1,upper = -1;
    for(int j = 0;j < n;j++) {
      if(arr[j] == m) {
        lower = j;
        break;
      }
    }
    if(lower != -1) {
      for(int j = n - 1;j >= 0;j--) {
        if(arr[j] == m) {
          upper = j;
          break;
        }
      }
    }
    cout<<lower<<" "<<upper<<endl;
  }
	return 0;
}
