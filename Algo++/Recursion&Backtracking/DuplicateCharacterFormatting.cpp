//Take as input str, a string. Write a recursive function which returns a new string in which all duplicate consecutive characters are 
//separated by a ‘ * ’. E.g. for “hello” return “hel*lo”. Print the value returned

#include<iostream>
#include<string.h>
using namespace std;

void insertAsterik(char *in,int i,int j) {
  if(i == strlen(in)) {
    return;
  }
  cout<<in[i];
  if(in[i] == in[i + 1]) {
    cout<<'*';
    insertAsterik(in,i + 1,j + 2);
  }
  else {
    insertAsterik(in,i + 1,j + 1);
  }    
}

int main() {
  char in[10000];
  cin>>in;
  insertAsterik(in,0,0);
	return 0;
}
