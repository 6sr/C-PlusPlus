//We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.

#include<iostream>
using namespace std;

int main() {
  int x,y,max = 0,a,b;
  cin>>x>>y;
  for(a = x;a <= y;a++) {
    for(b = a;b <= y;b++) {
      if(max < (a^b)) {
        max = (a^b);
      }
    }
  }
  cout<<max;
  return 0;
}
