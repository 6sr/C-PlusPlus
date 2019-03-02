#include<iostream>
using namespace std;

int done = 1111; // n times 1

void solve(int rowMask,int ld,int rd) {
    
    if(rowMask == done) {
        ans++;
        return ;
    }
    int safe = done& (~(rowMask|ld|rd));
    while(safe) {
        int p = safe&(-safe);
        safe = safe - p;
        solve(rowMask|p,ld|p,rd|p);
    }
}