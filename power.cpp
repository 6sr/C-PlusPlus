//#include <bits/stdc++.h>      // using this is a bad practice
#include<iostream>
using namespace std;

int power(int a,int n) {
    if(n == 0)
        return 1;
    int ans = power(a,n / 2);
    ans *= ans;
    if(n % 2 == 1)
        return  a * ans;
    return ans;
}

int main(){
    int a,n;
    cin>>a>>n;
    cout<<power(a,n)<<endl;
    return 0;
}