#include<iostream>
using namespace std;

int partition(int *arr,int low,int up) {
    int pivot = arr[up];
    int i = low - 1;
    for(int j = low;j < up;j++) {
        if(arr[j] <= pivot) {
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i + 1],arr[up]);
    return (i + 1);
}

void quickSort(int *arr,int low,int up) {
    if(low < up) {
        int part = partition(arr,low,up);
        quickSort(arr,low,part - 1);
        quickSort(arr,part + 1,up);
    }
}

int main() {
    int n;
    int *arr;
    arr = new int[n];
    for(int i = 0;i < n;i++) {
      cin>>arr[i];
    }
    quickSort(arr,0,n - 1);
    for(int i = 0;i < n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}

/*
int main() {
    int arr[] = {5,2,4,8,1,7};
    quickSort(arr,0,5);
    for(int i = 0;i < 6;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"LOL";
    return 0;
}
*/