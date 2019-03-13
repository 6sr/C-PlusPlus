//Prateek Bhayia likes to play with bits. One day Prateek bhayia decides to assign a task to his student Sanya. You have help Sanya to 
//complete this task. Task is as follows - Prateek Bhayia gives Q queries each query containing two integers a and b. Your task is to 
//count the no of set-bits in for all numbers between a and b (both inclusive)

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
  int q,a,b;
  int *arr;
  cin>>q;
  int t = q;
  arr = new int[q];
  while(q--) {
    cin>>a>>b;
    int ans = 0;
    for(int i = a;i <= b;i++) {
      ans += countSetBits(i);
    }
    arr[t - q - 1] = ans;
  }
  for(int i = 0;i < t;i++) {
    cout<<arr[i]<<endl;
  }
	return 0;
}
