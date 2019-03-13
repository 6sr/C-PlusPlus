//We are given a hashmap which maps all the letters with number. Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z. 
//Given a number, you have to print all the possible strings.

#include<iostream>
#include<cstring>
#include<set>
using namespace std;

set<string> s;
char getChar(int n) {
    if(n < 27 && n > 0) {
        return char(n + 64);
    }
    return '\0';
}

void subSequences(char *in,char *out,int i,int j) {
    char ch;
    if(in[i] == '\0') {
        out[j] = '\0';
        s.insert(out);
        return;
    }
    ch = getChar(in[i] - 48);
    out[j] = ch;
    subSequences(in,out,i + 1,j + 1);
    if(in[i + 1] != '\0') {
        ch = getChar((in[i] - 48) * 10 + (in[i + 1] - 48));
        if(ch != '\0') {
          out[j] = ch;
          subSequences(in,out,i + 2,j + 1);
        }
      }
    return;
}

int main() {
    char in[10];
    char out[10];
    cin>>in;
    subSequences(in,out,0,0);
    for(string str : s) {
      cout<<str<<endl;
    }
    return 0;
}
