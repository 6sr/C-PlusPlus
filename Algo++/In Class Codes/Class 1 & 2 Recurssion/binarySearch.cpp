#include<iostream>
using namespace std;

bool binarySearch(int no,int a[],int low,int up) {
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
    binarySearch(no,a,low,up);
}

int f = 0,l,m;
int bin(int *a,int n,int ele) {
    int ans;
    l = n - 1;
    m = (f + l) / 2;
    if(f > l) {
        return -1;
    }
    if(a[m] == ele) {
        return m;
    }
    else {
        if(a[m] < ele) {
            f = m + 1;
        }
        else {
            n = m;
        }
        ans = bin(a,n,ele);
        return ans;
    }
}

int main() {
    int a[] = {2,3,4,5,6,7,8};
    //Way 1
    cout<<bin(a,7,6);
    
    //Way 2
    if(binarySearch(3,a,0,6))
        cout<<"Exists";
    else
        cout<<"Not Exists";
            
    cout<<"\nLOL";
    return 0;
}