#include<iostream>
#include<string>
using namespace std;

void ascii(char* in,char* out,int i,int j) {
    if(in[i] == '\0') {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    //Including ascii value
    string a = to_string(int(in[i]));
    out[j] = a[0];
    out[j + 1] = a[1];
    ascii(in,out,i + 1,j + 2);
    out[j] = '\0';
    out[j + 1] = '\0';
    //Including alpha
    out[j] = in[i];
    ascii(in,out,i + 1,j + 1);
    //Not including anything
    ascii(in,out,i + 1,j);
}

int main() {
    char in[10],out[10];
    cin>>in;
    ascii(in,out,0,0);
    return 0;
}