/*
INCREDIBLE HULK
The Planet Earth is under a threat from the aliens of the outer space and the Marvel Avengers team is busy fighting against them. Meanwhile, The Incredible Hulk has to defeat an enemy who is N steps above the level where he is standing (assume it as the 0th level). Hulk, because of his incredible jumping ability can take jumps in power of 2. In order to defeat the enemy as quickly as possible he has to reach the Nth step in minimum moves possible. Help Hulk to find the same and contribute in saving the Mother Earth.

Input Format:
The first line contains the number of test cases T. T test cases follow: The first line of each test case contains a number N.

Constraints:
1 <= T <= 10 1 <= N <= 10^5

Output Format
Output T lines, containing the minimum number of moves required by Hulk to reach the Nth step
*/
#include<iostream>
using namespace std;

int countSetBits(int n) {
  int cnt = 0;
  while(n > 0) {
    n = n & (n - 1);
    cnt++;
  }
  return cnt;
}
int main() {
  int T,N[10];
  cin>>T;
  for(int i = 0;i < T;i++) {
    cin>>N[i];
  }
  for(int i = 0;i < T;i++) {
    cout<<countSetBits(N[i])<<endl;
  }
	return 0;
}