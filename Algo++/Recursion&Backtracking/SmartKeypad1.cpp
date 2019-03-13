//You will be given a numeric string S. Print all the possible codes for S.

//Following vector contains the codes corresponding to the digits mapped.

//string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

//For example, string corresponding to 0 is " " and 1 is ".+@$"
#include<iostream>
using namespace std;

char getChar(int n,int i) {
  if(n == 0) {
    return ' ';
  }
  if(n == 1) {
    if(i == 1) {
      return '.';
    }
    if(i == 2) {
      return '+';
    }
    if(i == 3) {
      return '@';
    }
    if(i == 4) {
      return '$';
    }
  }
  char ch = char(96 + 3 * (n - 2) + i);
  if(n <= 7 && n >= 2) 
    return ch;
  if(n >= 8 && n <= 9)
    return ch + 1;
  return '\0';
}

void getString(char *in,char *out,int i,int j) {
    if(in[i] == '\0') {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    int x;
    (in[i] == '7' || in[i] == '9')? x = 4 : x = 3;
    if(in[i] == '0') {
      x = 1;
    }
    if(in[i] == '1') {
      x = 4;
    }
    for(int k = 1;k <= x;k++) {
        out[j] = getChar(in[i] - 48,k);
        getString(in,out,i + 1,j + 1);
    }
}

int main() {
    char in[15];
    char out[20];
    cin>>in;
    getString(in,out,0,0);
    return 0;
}
