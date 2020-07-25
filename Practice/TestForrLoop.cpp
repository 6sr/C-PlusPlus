#include<iostream>
using namespace std;

int main() {
    // cnt = 166650 for both cases
    int n = 100, cnt = 0;
    // Case 1
    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            for(int k = j;k < n;k++) {
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
    cnt = 0;
    // Case 2
    for(int i = 0;i < n;i++) {
        for(int k = i + 1;k < n;k++) {
            for(int j = i + 1;j <= k;j++) {
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}
