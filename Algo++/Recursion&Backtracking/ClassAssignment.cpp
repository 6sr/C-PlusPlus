//In a mathematics class, Teacher ask Alice to find the number of all n digit distinct integers which is formed by the two distinct
//digits ai and bi but there is a rule to form n digit integer.

//Rule: She has to form n digit integer by using two digits ai and bi without consecutive bi.

//Alice is very weak in maths section. Help her to find the number of such n digit integers.
#include<iostream>
using namespace std;

int fib(int n) {
  if(n == 1) {
    return 2;
  }
  if(n == 2) {
    return 3;
  }
  if(n == 3) {
    return 5;
  }
  return fib(n - 1) + fib(n - 2);
}

int main() {
  int t,n;
  cin>>t;
  int a[t];
  for(int i = 0;i < t;i++) {
    cin>>n;
    a[i] = fib(n);
  }
  for(int i = 0;i < t;i++) {
    cout<<'#'<<i + 1<<" : "<<a[i]<<endl;
  }
	return 0;
}
