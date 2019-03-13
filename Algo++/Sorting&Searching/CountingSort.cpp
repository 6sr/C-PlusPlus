#include<iostream>
using namespace std;
int main() {
  int n,num;
  cin>>n;
  int cnt[1000005] = {0};
  for(int i = 0;i < n;i++) {
    cin>>num;
    cnt[num]++;
  }
  for(int i = 0;i < 1000005;i++) {
    while(cnt[i]--) {
      cout<<i<<" ";
    }
  }
	return 0;
}
