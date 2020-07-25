#include<iostream>
using namespace std;

int main() {
	// Find max no of persons present in a room such that 
	// probability of everyone having b'day on different day is prob
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