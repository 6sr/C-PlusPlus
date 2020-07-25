#include<iostream>
using namespace std;

bool binarySearch(int no,int a[],int low = 0,int up = 0) {
    int mid = (up + low) / 2;
    int x;
    if(a[mid] == no)
        return true;
    if(a[mid] > no)
        up = mid - 1;
    if(a[mid] < no)
        low = mid + 1;
    if(low > up)
        return false;
    return binarySearch(no,a,low,up);
}

int main() {
    int n;
    cin>>n;
    int *a;
    a = new int[n];
    for(int i = 0;i < n;i++) {
        cin>>a[i];
    }
    int search;
    cin>>search;
    if(binarySearch(search,a,0,n - 1))
        cout<<"Exists";
    else
        cout<<"Not Exists";
    return 0;
}