#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

int main() {
  int n;
  cin>>n;
  string str[n];
  for(int i = 0;i < n;i++) {
    cin>>str[i];
  }
  sort(str,str + n);
  
  /*
  for(int i = 0;i < n;i++) {
    int smallValue = 0;
    int idx = i;
    for(int j = i + 1;j < n;j++) {
     if(strcmp(str[idx].c_str(),str[j].c_str()) < smallValue) {
        smallValue = strcmp(str[idx].c_str(),str[j].c_str());
        idx = j;
      }
    }
    swap(str[idx],str[i]);
  }
  for(int i = 0;i < n / 2;i++) {
    swap(str[i],str[n - i - 1]);
  }
  */
  
  for(int i = 0;i < n - 1;i++) {
    if(str[i + 1].find(str[i]) != -1) {
      swap(str[i],str[i + 1]);
    }
  }
  for(int i = 0;i < n;i++) {
    cout<<str[i]<<endl;
  }
	return 0;
}
