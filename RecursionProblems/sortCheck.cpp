//#include <bits/stdc++.h>      // using this is a bad practice
#include<iostream>
using namespace std;

bool sortCheck(int arr[],int size){
    if(size == 1)
        return true;
    if(arr[0] <= arr[1] && sortCheck(arr + 1,size - 1))
        return true;
    return false;
}

int main(){
    int arr[] = {1,2,5,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    if(sortCheck(arr,size))
        cout<<"Sorted";
    else
        cout<<"Unsorted";
    cout<<"\nLOL";
    return 0;
}