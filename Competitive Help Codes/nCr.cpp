#include<iostream>
using namespace std;

int nCrGFG(int n, int r) {
    int ncrAns = 1;
    if (r > n - r) {
        r = n - r;
    }
    for (int i = 0; i < r;i++) {
        ncrAns *= (n - i);
        ncrAns /= (i + 1);
    }
    return ncrAns;
}

int nCr(int n,int r) {
    if(r > n) {
        cout<<"LOL";
        return 0;
    }
    if(n == r || r == 0) {
        return 1;
    }
    return (nCr(n - 1,r) + nCr(n - 1,r - 1));
}

int main() {
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r);
    return 0;
}