//We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. 
//Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )
#include<iostream>
using namespace std;

int getIthBit(int n,int p) {
    return (n & (1 << p)) > 0?1:0;
}

int main() {
    int *arr;
    int a = 0,b = 0;
    int j = 0,k = 0;
    int n;
    cin>>n;
    arr = new int [n + 1];
    int xorArray = 0;
    for(int i = 0;i < n;i++) {
      cin>>arr[i];
      xorArray = (xorArray^arr[i]);
    }
    int x = (xorArray & 1);
    int pos = 0;
    while(x != 1) {
        pos++;
        xorArray = (xorArray >> 1);
        x = (xorArray & 1);
    }
    for(int i = 0;i < n;i++) {
        x = getIthBit(arr[i],pos);
        if(x == 1) {
            b = (b^arr[i]);
        }
        else { 
            a = (a^arr[i]);
        }
    }
    cout<<a<<" "<<b;
    return 0;
}
