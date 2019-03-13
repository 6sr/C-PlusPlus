#include<iostream>
#include<stack>
using namespace std;

int getMax(stack<int> s,int k) {
  if(k == 0) {
    return -1;
  }
  int a = s.top();
  s.pop();
  int b = getMax(s,k - 1);
  s.push(a);
  if(b > a) {
    return b;
  }
  return a;
}
int main() {
  stack<int> s,st;
  int n,k,d;
  cin>>n;
  int m = 0;
  for(int i = 0;i < n;i++) {
    cin>>d;
    if(d > m) {
      m = d;
    }
    s.push(d);
  }
  cin>>k;
  if(n <= k) {
    cout<<m;
    return 0;
  }
  for(int i = 0;i < n - k + 1;i++) {
    st.push(getMax(s,k));
    s.pop();
  }
  while(!st.empty()) {
    cout<<st.top()<<" ";
    st.pop();
  }
	return 0;
}
