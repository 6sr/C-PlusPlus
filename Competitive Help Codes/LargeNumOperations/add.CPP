//Only if both nums are positive
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Me
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
    for(i = lenDiff - 1;i >= 0;i--) {
        int curr = (a[i] - '0') + carry;
        carry = curr / 10;
        ans = ans + to_string(curr % 10);
    }
    reverse(ans.begin(),ans.end());

    //Converts ans from 001 into 1
    for(i = 0;i < ans.size();i++) {
        if(ans[i] != '0') {
            break;
        }
    }
    ans = ans.substr(i);
    return ans;
}

//GeeksForGeeks
string add(string str1, string str2) {
    if (str1.length() > str2.length()) 
        swap(str1, str2);
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i = 0; i < n1; i++) { 
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
    string str[2];
    cin>>str[0]>>str[1];
    cout<<"Sum : "<<sum(str[0],str[1]);
    cout<<"\nAdd : "<<add(str[0],str[1]);
    return 0;
}