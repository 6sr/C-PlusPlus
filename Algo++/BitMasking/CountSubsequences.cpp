//Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a
//string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative 
//positions of the remaining characters. For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

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
    int t;
    cin>>t;
    int *ans;
    ans = new int[t + 1];
    for(int i = 0;i < t;i++) {
        in = new char[100005];
        out = new char[100005];
        cin>>in;
        subSequences(s,in,out,0,0);
        ans[i] = (s.size() % 1000000007);
        s.clear();
    }
    for(int i = 0;i < t;i++) {
      cout<<ans[i]<<endl;
    }
    return 0;
}
