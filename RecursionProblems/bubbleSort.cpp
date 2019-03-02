#include<iostream>
using namespace std;

void sort(int arr[],int i,int size){
    if(size == 1)   //Array of single element
        return;
    if(i == size - 1) {     //If reached at last of array while comparing
        sort(arr,0,size - 1);
        return;
    }
    if(arr[i] > arr[i + 1])     //comparing elements
        swap(arr[i],arr[i + 1]);
    sort(arr,i + 1,size);       //Rec case
    return;
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int size = sizeof(arr) / sizeof(int);
    sort(arr,0,size);
    for(int i = 0;i < size;i++)
        cout<<arr[i]<<" ";
    cout<<"\nLOL";    
    return 0;
}