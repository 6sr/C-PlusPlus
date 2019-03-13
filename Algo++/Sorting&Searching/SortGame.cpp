//Sanju needs your help! He gets a list of employees with their salary. The maximum salary is 100.

//Sanju is supposed to arrange the list in such a manner that the list is sorted in decreasing order of salary. And if two employees 
//have the same salary, they should be arranged in lexicographical manner such that the list contains only names of those employees having 
//salary greater than or equal to a given number x.

//Help Sanju prepare the same!
// i/p
79
4
Eve 78
Bob 99
Suzy 86
Alice 86
// o/p
Bob 99
Alice 86
Suzy 86

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int minSal,n;
  cin>>minSal>>n;
  pair<string,int> p[n];
  string s[n];
  int salary[n];
  for(int i = 0;i < n;i++) {
    cin>>s[i]>>salary[i];
  }
  int j = 0;
  for(int i = 0;i < n;i++) {
    if(salary[i] >= minSal) {
      p[j].second = salary[i];
      p[j].first = s[i];
      j++;
    }
  }
  n = j;
  for(int i = 0;i < n;i++) {
    int large = p[i].second;
    string lstr = p[i].first;
    int idx = i;
    for(int j = i + 1;j < n;j++) {
      if(p[j].second > large) {
        large = p[j].second;
        lstr = p[j].first;
        idx = j;
      }
    }
    swap(p[i],p[idx]);
  }

  for(int i = 0;i < n;i++) {
    int j = i;
    while(p[i].second == p[i + 1].second) {
      i++;
    }
    sort(p + j,p + i + 1);
  }

  for(int i = 0;i < n;i++) {
    cout<<p[i].first<<" "<<p[i].second<<endl;
  }  
  
	return 0;
}
