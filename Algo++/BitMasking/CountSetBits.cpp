#include<iostream>
using namespace std;

int countSetBits(int n) {
    int cnt = 0;
    while(n) {
        cnt++;
        n = (n & (n - 1));
    }
    return cnt;
}

int main() {
  int t;
  cin>>t;
  int *arr;
  arr = new int[t];
 for(int i = 0;i < t;i++) {
    cin>>arr[i];
 }
 for(int i = 0;i < t;i++) {
    cout<<countSetBits(arr[i])<<endl;
  }
	return 0;
}
