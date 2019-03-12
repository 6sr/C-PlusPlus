/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, the size of second array and 
take M more inputs and store that in second array. Write a function that returns the sum of two arrays. Print the value returned.
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string sum(string a,string b) {
  string temp = a;
  a = (a.length() > b.length())?a:b;
  b = (temp.length() > b.length())?b:temp;
  int lenDiff = a.length() - b.length();
  int carry = 0;
  string ans = "";
  int i;
  for(i = b.length() - 1;i >= 0;i--) {
    int curr = (a[i + lenDiff] - '0') + (b[i] - '0') + carry;
    ans = ans + to_string(curr % 10);
    carry = curr / 10;
  }
  for(i = lenDiff;i >= 0;i--) {
    int curr = (b[i] - '0') + carry;
    carry = curr / 10;
    ans = ans + to_string(curr % 10);
  }
  return ans;
}

string add(string str1, string str2) {
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) { 
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry); 
        str.push_back(sum % 10 + '0'); 
        carry = sum / 10; 
    } 
  
    for (int i = n1; i < n2; i++) { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum % 10 + '0');
        carry = sum / 10; 
    }
    if(carry != 0) {
      str.push_back(carry + '0');
    }
    reverse(str.begin(), str.end());
    return str;
}

int main() {
  int n,digit;
  string str[2];
  for(int i = 0;i < 2;i++) {
    cin>>n;
    for(int j = 0;j < n;j++) {
      cin>>digit;
      str[i] = str[i] + char(digit + 48);
    }
  }
  string ans = add(str[0],str[1]);
  for(int i = 0;i < ans.length();i++) {
    cout<<ans[i]<<", ";
  }
  cout<<"END";
	return 0;
}
