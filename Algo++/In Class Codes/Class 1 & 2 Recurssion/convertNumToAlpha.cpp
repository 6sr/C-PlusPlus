#include<iostream>
using namespace std;

char digits[][10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int convertAlpha(int n){
    if(n == 0){
        return 0;
    }
    convertAlpha(n / 10);
    cout<<digits[n % 10]<<" ";
    return 0;
}

int main(){
    convertAlpha(76345);       
    cout<<"\nLOL";
    return 0;
}