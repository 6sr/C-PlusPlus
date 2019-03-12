/*
Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it 
with digit 9 - t.

Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits.
The decimal representation of the final number shouldn't start with a zero.
4545 gives 4444
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    string ans = "";
    cin>>str;
    if(str == "0") {
        cout<<"0";
    }
    for(int i = 0 ;i < str.length();i++) {
        int curr = str[i] - '0';
        int invert = 9 - curr;
        if(invert < curr) {
            curr = invert;
        }
        ans += char(curr + 48);
    }
    if(ans[0] == '0') {
      ans[0] = '9';
    }
    cout<<ans;
    return 0;
}
