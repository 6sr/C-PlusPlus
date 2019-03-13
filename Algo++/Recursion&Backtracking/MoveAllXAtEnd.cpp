//Take as input str, a string. Write a recursive function which moves all ‘x’ from the string to its end. E.g. for “abexexdexed”
//return “abeedeedxxx”. Print the value returned

#include<iostream>
#include<string.h>
using namespace std;

void printX(char *in,int i,int x) {
  if(i == strlen(in)) {
    for(int j = 0;j < x;j++) {
      cout<<"x";
    }
    return;
  }
  
  if(in[i] != 'x') {
    cout<<in[i++];
  }
  else {
    i++;
    x++;
  }
  printX(in,i,x);
}

int main() {
  char in[10000];
  cin>>in;
  printX(in,0,0);
	return 0;
}
