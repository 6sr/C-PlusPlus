#include<iostream>
using namespace std;

int main() {
    float prob;
    cin>>prob;
    float x = 1.0;
    int i = 0;
    while(x > prob) {
        x *= (365 - i) / 365.0;
        i++;
    }
    cout<<"No of persons : "<<i<<" Prob : "<<x<<endl;
    return 0;
}