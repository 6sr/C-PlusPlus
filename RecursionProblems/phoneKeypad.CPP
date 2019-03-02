#include<iostream>
using namespace std;

int cnt = 0;
char getChar(int n,int i) {
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
        cnt++;
        cout<<out<<endl;
        return;
    }
    int x;
    (in[i] == '7' || in[i] == '9')? x = 4 : x = 3;
    for(int k = 1;k <= x;k++) {
        out[j] = getChar(in[i] - 48,k);
        getString(in,out,i + 1,j + 1);
    }
}

int main() {
    char in[] = "279";
    char out[100];
    getString(in,out,0,0);
    cout<<"No of strings : "<<cnt;
    return 0;
}