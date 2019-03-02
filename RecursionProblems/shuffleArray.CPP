#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;

int getRand(int low,int up) {
    if(low == up || low == up - 1) {
        return low;
    }
    srand(time(0));
    int x = rand() % (up - low) + low;
    //cout<<"X : "<<x;
    return x;
}

int main() {
    int arr[] = {3,2,6,5,4,7,1};
    int n = sizeof(arr) / sizeof(int);
    cout<<"Size : "<<n<<endl;
    sort(arr,arr + n);
    for(int i = 0;i < n;i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    for(int i = 0;i < n - 1;i++) {
        int j = getRand(i + 1,n);
        swap(arr[i],arr[j]);
    }
    for(int i = 0;i < n;i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<"\nLOL";
    return 0;
}



//My Method
/*
int getRand(int low,int up) {
    srand(time(0));
    return rand() % up + low;
}

bool checkSame(int *a,int *b,int size) {
    for(int i = 0;i < size;i++) {
        if(a[i] == b[i])
            return false;
    }
    return true;
}

int main() {
    int arr[] = {3,2,6,5,4,7,1};
    int b[100];
    int n = sizeof(arr) / sizeof(int);
    sort(arr,arr + n);
    for(int i = 0;i < n;i++) {
        b[i] = arr[i];
    }
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
    srand(time(0));    
    do {
        for(int i = 0;i < n;i++) {
            int r = rand() % n;
            int s = rand() % n;
            //cout<<r<<" "<<s<<endl;
            swap(arr[r],arr[s]);
        }
    }while(!checkSame(arr,b,n));
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<"  ";
    return 0;
}
*/