//Take as input S, a string. Write a function that removes all consecutive duplicates. Print the value returned.

#include<iostream>
using namespace std;
int main() {
  char in[10000];
  cin>>in;
  for(int i = 0;in[i] != '\0';i++) {
    cout<<in[i];
    while(in[i] == in[i + 1]) {
      i++;
    }
  }
	return 0;
}
