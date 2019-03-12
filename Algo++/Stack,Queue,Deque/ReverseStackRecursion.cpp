#include<iostream>
#include<stack>

using namespace std; 

stack<int> st; 
int insert_at_bottom(int x) {
    if(st.size() == 0)
      st.push(x); 
    else { 
        int a = st.top(); 
        st.pop(); 
        insert_at_bottom(x); 
        st.push(a); 
    } 
} 
int reverse() { 
    if(st.size()>0) { 
        int x = st.top(); 
        st.pop(); 
        reverse(); 
        insert_at_bottom(x); 
    }
} 
  
int main() {
    int n,d;
    cin>>n;
    for(int i = 0;i < n;i++) {
      cin>>d;
      st.push(d);
    }
    reverse(); 
    while(!st.empty()) { 
        int p=st.top(); 
        st.pop();
        cout<<p<<endl;
    } 
    return 0; 
} 
