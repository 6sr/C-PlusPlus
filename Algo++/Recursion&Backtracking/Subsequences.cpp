//Take as input str, a string. We are concerned with all the possible subsequences of str. E.g.

// a. Write a recursive function which returns the count of subsequences for a given string. Print the value returned.

// b. Write a recursive function which prints all possible subsequences for a “abcd” has following subsequences
// “”, “d”, “c”, “cd”, “b”, “bd”, “bc”, “bcd”, “a”, “ad”, “ac”, “acd”, “ab”, “abd”, “abc”, “abcd”.given string 
// (void is the return type for function). 
// Note: Use cin for input

#include<iostream>
#include<string>
#include<stack>
using namespace std;

void subSequences(stack<string> &s,char *in,char *out,int i,int j) {
    //Base case
    if(in[i] == '\0') {
        out[j] = '\0';
        s.push(out);
        return;
    }
    //Rec case
    out[j] = in[i];
    subSequences(s,in,out,i + 1,j + 1);
    subSequences(s,in,out,i + 1,j);
}

int main() {
    char *in;
    char *out;
    stack<string> s;
    in = new char[100005];
    out = new char[100005];
    cin>>in;
    subSequences(s,in,out,0,0);
    cout<<s.size()<<endl;
    while(!s.empty()) {
      cout<<s.top()<<" ";
      s.pop();
    }
    return 0;
}
