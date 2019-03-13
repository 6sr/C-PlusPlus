// x^k = n
#include<iostream>
#include<cmath>
using namespace std;

long long calLog(long long n,int k) {
  if(k == 1) {
    return n;
  }
  int root = int(sqrt(n));
  if(k == 2) {
    return root;
  }
  long long x = 1;
  float ans = log10(n) / k;
  for(;x <= root + 1;x++) {
    if(log10(x) > ans) {
      break;
    }
  }
  return x - 1;
}

int main() {
  long long n;
  int t,k;
  cin>>t;
  for(int i = 0;i < t;i++) {
    cin>>n>>k;
    cout<<calLog(n,k)<<endl;
  }
	return 0;
}
