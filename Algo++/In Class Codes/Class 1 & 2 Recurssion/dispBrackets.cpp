#include<iostream>
#include<set>
#include<string>
using namespace std;

set<string> s;

//By sir
void generateParenthesis(string str,int n,int open,int close) {
    if(close >= n) {
        cout<<str<<endl;
        return;
    }
    if(open < n) {
        generateParenthesis(str + '(',n,open + 1,close);
    }
    if(close < open) {
        generateParenthesis(str + ')',n,open,close + 1);
    }
    return;
}


//By Me
void dispBrackets(char *out,int i,int j,int n) {    //i is counter for open brackets , j is counter for closed brackets
    //if(i == j && i != 0) {      //No effect why?
      //  out[i + j] == '(';
    //  }
    if(i == n) {
        for(;j < n;j++) {
            out[i + j] = ')';
        }
        out[i + j] = '\0';
        cout<<" Final : "<<out<<endl;
        return;
    }
    //if(i < n) {
    out[i + j] = '(';
    i++;
    dispBrackets(out,i,j,n);
    //}
    if(i != n) {    //Helps in removing repitition of cases
        out[i + j] = ')';
        j++;
        dispBrackets(out,i,j,n);
    }
}

int main() {
    char out[100];
    int n;
    cin>>n;
    dispBrackets(out,0,0,n);
    //generateParenthesis("",n,0,0);
    cout<<"LOL";
    return 0;
}