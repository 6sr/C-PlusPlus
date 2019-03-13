//Given a string containing duplicates, print all its distinct permutations such that there are no duplicate permutations and all 
//permutations are printed in a lexicographic order.

//NOTE: DO NOT USE MAP OR SET.
#include<iostream>
#include<string>
#include<set>
using namespace std;
void permutate(set<string> &s,char *in,int i) {
    //Base case
    if(in[i] == '\0') {
        s.insert(in);
        return;
    }
    //Rec case
    for(int j = i;in[j] != '\0';j++) {
        swap(in[i],in[j]);
        permutate(s,in,i + 1);
        //Backtracking
        swap(in[i],in[j]);
    }
}

int main() {
    char in[100];
    cin>>in;
    set<string> s;
    permutate(s,in,0);
    for(string str : s) {
      cout<<str<<endl;
    }
    return 0;
}
