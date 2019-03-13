//We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once. 
//Find the unique number. Only use - bitwise operators, and no extra space.

#include<iostream>
#include<math.h>
using namespace std;

void add(int *arr,int n) {
    int len = sizeof(arr) / sizeof(int);
    int i = 1;
    while(n > 0) {
        arr[32 - i] += n % 2;
        n /= 2;
        i++;
    }
}

int main() {
    int arr[32] = {0};
    int *no;
    int n;
    cin>>n;
    no = new int[n];
    for(int i = 0;i < n;i++) {
      cin>>no[i];
    }
    for(int i  = 0;i < n;i++) {
        add(arr,no[i]);
    }
    for(int i = 0;i <= 31;i++) {
        arr[i] = arr[i] % 3;
    }
    int uniqueNum = 0;
    for(int i = 31;i >= 0;i--) {
        uniqueNum += (pow(2,i) * arr[31 - i]);
    }
    cout<<uniqueNum;
    return 0;
}
