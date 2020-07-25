#include<iostream>
using namespace std;

istream& operator>>(istream &a,int arr[]) {
    int d;
    cin>>d;
    while(d != -1) {
        cin>>d;
    }
    return a;
}

ostream& operator<<(ostream &a,int arr[]) {     // try for <<< or ->
    cout<<arr[0];
    return a;
}

int main() {
    int arr[10];
    cin>>arr;
    cout<<arr;
    
    return 0;
}