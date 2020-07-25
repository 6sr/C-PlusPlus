//#include <bits/stdc++.h>      // using this is a bad practice
#include<iostream>
using namespace std;

int * sort(int a[],int n) {
    int end = n - 1;	//Points to 2 from end
    int start = 0;		//Points to 0 from start
    int mid = 0;		//Points to 1 from start
    while(mid < end) {
      if(a[mid] == 0){
        swap(a[start],a[mid]);
        start++;
        mid++;
      }
      else if(a[mid] == 1){
        mid++;
      }
      else if(a[mid] == 2){
        swap(a[mid],a[end]);
        end--;
      }
    }
    return a;
}

int main(){
    int a[] = {2,1,0,1,1,2,0};
    sort(a,7);
    for(int i = 0;i < 7;i++)
        cout<<a[i]<<" ";
    return 0;
}