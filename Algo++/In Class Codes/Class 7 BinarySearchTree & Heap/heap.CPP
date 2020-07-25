#include<iostream>
#include<vector>
using namespace std;

//Min Heap
class Heap {
    vector<int> v;

public :
    Heap(int ds = 1000) {
        v.reserve(ds);
        v.push_back(-1);
    }
    bool empty() {
        return v.size() == 1;
    }
    void push(int data) {
        v.push_back(data);
        int idx = v.size() - 1;
        int parent = idx / 2;
        while(idx > 1 && v[idx] < v[parent]) {
            swap(v[idx],v[parent]);
            idx = parent;
            parent = idx / 2;
        }
    }
    int top() {
        return v[1];
    }
    void pop() {
        int last_idx = v.size() - 1;
        swap(v[last_idx],v[1]);
        v.pop_back();
        heapify(1);
    }
    void heapify(int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int min_i = i;
        if(left < v.size() && v[left] < v[min_i]) {
            min_i = left;
        }
        if(right < v.size() && v[right] < v[min_i]) {
            min_i = right;
        }
        //Heapifying whole heap
        //in place heap sort
        //Order n
        /*
        for(int j = n / 2;j >= 1;j--) {
            heapify(j);
        }
        */
        if(min_i != i) {
            //kind of base case + rec case
            swap(v[min_i],v[i]);
            heapify(min_i);
        }
    }
};

int main() {
    Heap h;
    int d;
    cin>>d;
    while(d != -1) {
        h.push(d);
        cin>>d;
    }
    while(!h.empty()) {
        cout<<h.top()<<"  ";        //a[i++] = h.top();     heap sort nlogn complexity
        //min heap sorts in ascending order
        //max heap sorts in descending order
        //in place heap sort
        h.pop();
    }
}

/*
#include<iostream>
using namespace std;
int main() {
  int n,max = 0;
  cin>>n;
  int arr[n];
  for(int i = 0;i < n;i++) {
    cin>>arr[i];
  }
  int idx = 0;
  int i = 0,j = n - 1;
  while(i < j) {
    if(idx % 2 == 0) {
      if(arr[i] > arr[j]) {
        max += arr[i];
        i++;
      }
      else if(arr[i] <= arr[j]) {
        max += arr[j];
        j--;
      }
    }
    else {
      if(arr[i] > arr[j]) {
        i++;
      }
      else if(arr[i] <= arr[j]) {
        j--;
      }
    }
    idx++;
  }
  cout<<max;
  
	return 0;
}
*/