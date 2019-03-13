//Take as input str, a string. str represents keys pressed on a nokia phone keypad. We are concerned with all possible words that 
//can be written with the pressed keys.
//Assume the following alphabets on the keys: 1 -> abc , 2 -> def , 3 -> ghi , 4 -> jkl , 5 -> mno , 6 -> pqrs , 7 -> tuv , 
//8 -> wx , 9 -> yz

//E.g. “12” can produce following words “ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”

//a. Write a recursive function which returns the count of words for a given keypad string. Print the value returned.

//b.Write a recursive function which prints all possible words for a given keypad string (void is the return type for function).

#include<iostream>
using namespace std;

int cnt = 0;
char getChar(int n,int i) {
    char ch = char(96 + 3 * (n - 1) + i);
    if(n < 7 && n >= 1) 
        return ch;
    if(n == 8 || n == 7)
        return ch + 1;
    if(n == 9) {
      if(i == 1) {
        return 'y';
      }
      if(i == 2) {
        return 'z';
      }
    }    
    return '\0';
}

void getString(char *in,char *out,int i,int j) {
    if(in[i] == '\0') {
        out[j] = '\0';
        cout<<out<<" ";
        return;
    }
    int x = 3;
    if(in[i] == '6') {
      x = 4;
    }
    if(in[i] == '8' || in[i] == '9') {
      x = 2;
    }
    for(int k = 1;k <= x;k++) {
        out[j] = getChar(in[i] - 48,k);
        getString(in,out,i + 1,j + 1);
    }
}

void getStringCnt(char *in,int i) {
    if(in[i] == '\0') {
        cnt++;
        return;
    }
    int x = 3;
    if(in[i] == '6') {
      x = 4;
    }
    if(in[i] == '8' || in[i] == '9') {
      x = 2;
    }
    for(int k = 1;k <= x;k++) {
        getStringCnt(in,i + 1);
    }
}

int main() {
    char in[100000];
    char out[100000];
    cin>>in;
    getStringCnt(in,0);
    cout<<cnt<<endl;
    getString(in,out,0,0);
    return 0;
}
