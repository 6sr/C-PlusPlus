//Replace all occurrences of pi with 3.14

#include<iostream>
#include<string.h>
using namespace std;
int main() {
  int t;
  cin>>t;
  char in[t][1000];
  for(int i = 0;i < t;i++) {
    cin>>in[i];
  }
  for(int i = 0;i < t;i++) {
    for(int j = 0;j < strlen(in[i]);j++) {
      if(in[i][j] == 'p' && in[i][j + 1] == 'i') {
        cout<<"3.14";
        j++;
        continue;
      }
      cout<<in[i][j];
    }
    cout<<endl;
  }
	return 0;
}
