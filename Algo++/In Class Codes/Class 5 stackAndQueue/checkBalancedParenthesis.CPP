#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool checkBalancedParenthesis(string str) {
    stack<char> s;
    for(int i = 0;i < str.length();i++) {
        char curr = str[i];
        if(curr == '(') {
            s.push(curr);
        }
        else if(curr == ')') {
            if(s.empty()) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

bool checkRedundant(string str) {
    stack<char> s;
    for(int i = 0;i < str.length();i++) {
        char curr = str[i];
        if(str[i] == '(' && str[i + 1] == ')')
            return true;
        if(curr != ')') {
            s.push(curr);
        }
        else if(str[i + 1] == ')') {
            while(s.top() != '('){
                s.pop();
            }
            s.pop();
            if(s.top() == '(') {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string str = "((a + b)())";
    cout<<checkRedundant(str);
    return 0;
}

/*
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int open = 0;

bool checkBalancedParenthesis(char* str) {
    for(int i = 0;i < strlen(str);i++) {
        char curr = str[i];
        if(curr == '(') {
            open++;
        }
        else if(curr == ')') {
            if(open == 0) {
                return false;
            }
            open--;
        }
    }
    return (open == 0);
}

int main() {
  char in[100005];
  cin>>in;
  if(checkBalancedParenthesis(in)) {
    cout<<"Yes";
  }
  else {
    cout<<"No";
  }
  return 0;
}
*/