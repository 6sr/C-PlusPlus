/*
You are provided n numbers of array. You need to find the maximum length of bitonic subarray. A subarray A[i … j] is biotonic if 
there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] i.e subarray is first 
increasing and then decreasing or entirely increasing or decreasing.
2
6
12 4 78 90 45 23
4
40 30 20 10
Ans - 5 4
*/
//Biotonic array
#include<iostream>
using namespace std;

int isDec(int *arr,int n,int idx) {
  int k = 0;
  for(int i = idx;i < n - 1;i++) {
    if(arr[i] >= arr[i + 1]) {
      k++;
    }
    else {
      return k + 1;
    }
  }
  return k + 1;
}

int isInc(int *arr,int n,int idx) {
  int k = 0;
  for(int i = idx;i < n - 1;i++) {
    if(arr[i] <= arr[i + 1]) {
      k++;
    }
    else {
      return k + 1;
    }
  }
  return k + 1;
}

int main() {
  int t,n;
  cin>>t;
  for(int i = 0;i < t;i++) {
    cin>>n;
    int arr[n];
    for(int j = 0;j < n;j++) {
      cin>>arr[j];
    }
    int max = 0;
    for(int j = 0;j < n;j++) {
      int inc = isInc(arr,n,j);
      int dec = isDec(arr,n,j + inc - 1);
      if(max < inc + dec - 1) {
        max = inc + dec - 1;
      }
    }
    cout<<max<<endl;
  }
	return 0;
}
