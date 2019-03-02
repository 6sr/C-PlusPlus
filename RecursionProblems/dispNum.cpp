//#include <bits/stdc++.h>      // using this is a bad practice
#include<iostream>
using namespace std;

void dispDec(int n){  //Bottom To Up
    if(n == 0)
        return;
    cout<<n<<" ";
    dispDec(n - 1);
    return;
}

void dispInc(int n) {  //Top To Down
    //static int i = 1;
    /*
    if(n == 0)
        return;
    cout<<inc<<" ";
    inc++;
    dispInc(n - 1);
    return;
    */
    if(n == 0)
        return;
    dispInc(n - 1);
    cout<<n<<" ";
    return;
}

int main(){
    int n;
    cin>>n;
    dispDec(n);
    cout<<endl;
    dispInc(n);
}