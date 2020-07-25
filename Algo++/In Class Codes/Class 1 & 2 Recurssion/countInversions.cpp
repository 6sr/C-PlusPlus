#include<iostream>
using namespace std;

int merge(int *a,int s,int e) {
    int temp[1000];
    int  i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    int  k = s;
    int count = 0;
    while(i <= mid && j <= e) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            count += mid - i + 1;
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
    return count;
}

int mergeSort(int *a,int s,int e) {
    if(s >= e) {
        return 0;
    }
    int mid = (s + e) / 2;

    int x = mergeSort(a,s,mid);
    int y = mergeSort(a,mid + 1,e);
    int z = merge(a,s,e);    //Cross Inversions
    return x + y + z;
}

int main() {
    int a[] = {1,5,2,6,3,0};
    int ans = mergeSort(a,0,5);
    for(int i = 0;i < 6;i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\nAns : "<<ans;
    return 0;
}