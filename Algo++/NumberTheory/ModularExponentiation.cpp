//Given three numbers a,b,c. Calculate (a^b)mod c.

#include<iostream>
using namespace std;

#define ll long long

int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  ll ans = 1;
  a = a % c;
  for(ll i = 1;i <= b;i++) {
    ans = ans % c;
    ans = ans * a;
    ans = ans % c;
  }
  ans = ans % c;
  cout<<ans;
	return 0;
}
