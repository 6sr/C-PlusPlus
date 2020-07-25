#include<iostream>
#include<math.h>
using namespace std;

void disp(int *arr) {
    int len = sizeof(arr) / sizeof(int);
    for(int i = 0;i < len;i++) {
        cout<<arr[i]<<" ";
    }
    //cout<<"  len : "<<len<<endl;
}

void add(int *arr,int n) {
    int len = sizeof(arr) / sizeof(int);
    int i = 1;
    //cout<<"No : "<<n<<"LOL";
    while(n > 0) {
        //cout<<"NO : "<<n<<"  "<<arr[32 - i]<<endl;
        arr[32 - i] += n % 2;
        //cout<<arr[32 - i]<<"LOLOLOL";
        n /= 2;
        i++;
    }
    //cout<<"\nLOL\n";
    //disp(arr);
}

int main() {
    int arr[32] = {0};
    char no[100] = {3,2,15,5,2,3,5,5,3,2};
    //int n = sizeof(no) / sizeof(char);
    //cout<<n<<endl;
    for(int i  = 0;i < 10;i++) {
        add(arr,no[i]);
        //cout<<"No main  "<<no[i] - 48<<"    ";
    }
    for(int i = 0;i <= 31;i++) {
        arr[i] = arr[i] % 3;
    }
    int uniqueNum = 0;
    for(int i = 31;i >= 0;i--) {
        uniqueNum += (pow(2,i) * arr[31 - i]);
    }
    cout<<"Unique number : "<<uniqueNum;
    return 0;
}