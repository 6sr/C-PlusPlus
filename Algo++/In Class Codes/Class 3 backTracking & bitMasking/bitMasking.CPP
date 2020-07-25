#include<iostream>
using namespace std;

int getLastBit(int n) {
    return (n & 1);
}

int getIthBit(int n,int p) {
    int c = (n & (1 << p));
    if(c > 0)
        return 1;
    else
        return 0;
}

void setIthBit(int &n,int p) {
    n = (n | (1 << p));
}

void setIToJ(int &n,int i,int j) {
    int ithBit = (n & (1 << i));
    if(i < j)
        ithBit = (ithBit << (j - i));
    else
        ithBit = (ithBit >> (i - j));
    n = (n & ithBit);
}

int countSetBits1(int n) {
    int cnt = 0;
    while(n > 0) {
        cnt += (n & 1);
        n = (n >> 1);
    }
    return cnt;
}

int countSetBits2(int n) {
    int cnt = 0;
    while(n) {
        cnt++;
        n = (n & (n - 1));
    }
    return cnt;
}

int countSetBits3(int n) {
    int cnt = 0;
    while(n) {
        int p = n & (-n);
        n = n - p;
        cnt++;
    }
    return cnt;
}
//Speed of counting setBits 3 == 2 > 1

int main() {
    int n;
    cin>>n;
    cout<<"Last bit : "<<getLastBit(n);
    cout<<"\nthird last bit : "<<getIthBit(n,3)<<endl;
    setIthBit(n,3);
    cout<<"After setting : "<<n;
    //cout<<"Bit : "<<showbits(n);
    //cout<<__builtin_popcount(n)<<endl;        //try this
    return 0;
}
