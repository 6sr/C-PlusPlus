//#include <bits/stdc++.h>      // using this is a bad practice
#include<iostream>
#include<cstring>
using namespace std;

char getChar(int n) {
    if(n < 27 && n > 0) {
        return char(n + 96);
    }
    return '\0';
}

void subSequences(char *in,char *out,int i,int j) {
    char ch;
    if(in[i] == '\0') {
        out[j] = '\0';
        cout<<out<<endl;
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
    char in[] = "123";
    char out[100];
    //char out[100];
    subSequences(in,out,0,0);
    return 0;
}