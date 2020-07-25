#include<iostream>
using namespace std;

void merge(int *a,int s,int e) {
    int temp[1000];
    int  i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    int  k = s;
    while(i <= mid && j <= e) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }
    while(i <= mid) {
        temp[k++] = a[i++];
    }
    while(j <= e) {
        temp[k++] = a[j++];
    }
    for(i = s;i <= e;i++)
        a[i] = temp[i];
    return;
}

void mergeSort(int *a,int s,int e) {
    //Base case
    if(s >= e)
        return;
    //Recurssive Case
    int mid = (s + e) / 2;
    mergeSort(a,s,mid);
    mergeSort(a,mid + 1,e);
    merge(a,s,e);
    return;
}

int main() {
    int a[] = {8,5,3,6,2,7};
    int n = sizeof(a) / sizeof(int);

    mergeSort(a,0,n - 1);

    for(int i = 0;i < 6;i++)
        cout<<a[i]<<" ";
    return 0;
}