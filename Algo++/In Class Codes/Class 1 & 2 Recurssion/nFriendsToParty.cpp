#include<iostream>
using namespace std;

int goToParty(int n) {
    if(n == 1 || n == 2) {    //base case
        return n;
    }
    int nWays = goToParty(n - 1) + (n - 1) * goToParty(n - 2);
    return nWays;
}

int main() {
    int n = 5;
        cout<<goToParty(n)<<endl;
    return 0;
}