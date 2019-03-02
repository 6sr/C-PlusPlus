//#include <bits/stdc++.h>      // using this is a bad practice
#include<iostream>
#include<string>
#include<set>
using namespace std;

void subSequences(set<string> &s,char *in,char *out,int i,int j) {
    //
    if(in[i] == '\0') {
        out[j] = '\0';
        s.insert(out);
        cout<<out<<endl;
        return;
    }
    //Rec case
    out[j] = in[i];
    subSequences(s,in,out,i + 1,j + 1);
    subSequences(s,in,out,i + 1,j);
}

int main() {
    char in[] = "abc";
    char out[100];
    set<string> s;
    subSequences(s,in,out,0,0);
    cout<<"LOL";
    for(string str : s) {
        cout<<str<<endl;
    }
    return 0;
}

/*
#include<iostream>
#include<string>
using namespace std;

void subSequences(int &ans,char *in,char *out,int i,int j) {
    //Base case
    if(in[i] == '\0') {
        out[j] = '\0';
        ans = (ans + 1) % 1000000007;
        return;
    }
    //Rec case
    out[j] = in[i];
    subSequences(ans,in,out,i + 1,j + 1);
    subSequences(ans,in,out,i + 1,j);
}

int main() {
    char *in;
    char *out;
    int t;
    cin>>t;
    int *ans;
    ans = new int[t + 1];
    for(int i = 0;i < t;i++) {
        in = new char[100005];
        out = new char[100005];
        cin>>in;
        subSequences(ans[i],in,out,0,0);
    }
    for(int i = 0;i < t;i++) {
      cout<<ans[i]<<endl;
    }
    return 0;
}
*/

/*
#include<iostream>
#include<string>
#include<set>
using namespace std;

void subSequences(set<string> &s,char *in,char *out,int i,int j) {
    //Base case
    if(in[i] == '\0') {
        out[j] = '\0';
        s.insert(out);
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
    set<string> s;
    in = new char[100005];
    out = new char[100005];
    cin>>in;
    subSequences(s,in,out,0,0);
    cout<<s.size()<<endl;
    for(string str : s) {
      cout<<str<<" ";
    }
    return 0;
}
*/

/*
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
*/