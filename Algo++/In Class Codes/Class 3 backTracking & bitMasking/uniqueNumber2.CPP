#include<iostream>
using namespace std;

int getIthBit(int n,int p) {
    return (n & (1 << p)) > 0?1:0;
}

int main() {
    int *arr;
    int a = 0,b = 0;
    int j = 0,k = 0;
    int n;
    cin>>n;
    arr = new int [n + 1];
    int xorArray = 0;
    for(int i = 0;i < n;i++) {
      cin>>arr[i];
      xorArray = (xorArray^arr[i]);
    }
    int x = (xorArray & 1);
    int pos = 0;
    while(x != 1) {
        pos++;
        xorArray = (xorArray >> 1);
        x = (xorArray & 1);
    }
    for(int i = 0;i < n;i++) {
        x = getIthBit(arr[i],pos);
        if(x == 1) {
            b = (b^arr[i]);
        }
        else { 
            a = (a^arr[i]);
        }
    }
    cout<<a<<" "<<b;
    return 0;
}


/*
void disp(int *arr,int n) {
    for(int i = 0;i < n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int getXOR(int *arr,int n) {
    //cout<<"Size : "<<n<<endl;
    if(n == 1)
        return arr[0];
    int no = arr[0] ^ arr[1];
    for(int i = 2;i < n;i++) {
        //cout<<no<<" ";
        no = (no ^ arr[i]);
    }
    return no;
}

int getIthBit(int n,int p) {
    return (n & (1 << p)) > 0?1:0;
}

int main() {
    int arr[] = {3,1,5,7,2,3,5,1};
    int a[100],b[100];
    int j = 0,k = 0;
    int n = sizeof(arr) / sizeof(int);
    //cout<<n<<endl;
    int xorArray = getXOR(arr,n);
    //cout<<xorArray<<endl;
    int x = (xorArray & 1);
    int pos = 0;
    while(x != 1) {
        pos++;
        xorArray = (xorArray >> 1);
        x = (xorArray & 1);
    }
    for(int i = 0;i < n;i++) {
        x = getIthBit(arr[i],pos);
        if(x == 1) {
            b[k++] = arr[i];
        }
        else { 
            a[j++] = arr[i];
        }
    }
    //disp(a,j);
    //disp(b,k);
    cout<<getXOR(a,j)<<endl;
    cout<<getXOR(b,k);
}
*/