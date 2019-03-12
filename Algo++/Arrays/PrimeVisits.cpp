/*
PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries between a and b (inclusive) , 
However due to shortage of time he can't visit each and every country , So PM Modi decides to visit only those countries,for 
which country number has two divisors. So your task is to find number of countries Mr. Modi will visit.
i/p
2
1 10
11 20
o/p
4
4
*/
#include <iostream>
using namespace std;

//PRIME SIEVE & OPTIMISATIONS
#define ll long long

void primeSieve(int *p,ll n){

    p[0] = p[1] = 0;
    p[2] = 1;

    //Let us Mark all Odd Numbers as Prime(Initialisations)
    for(ll i=3;i<=n;i+=2){
        p[i] = 1;
    }

    //Sieve Login to mark non prime numbers as 0
    //1. Optimsation : Iterate only over odd Numbers
    for(ll i=3;i<=n;i+=2){
        
        if(p[i]){
            //Mark all the multiples of that number as not prime.
            //2. Optimisation Take a jump of 2i starting from i*i
            for(ll j=i*i;j<=n;j+=2*i){
                p[j] = 0;
            }
        }

    }
    return;
}

int main() {
    ll N = 1000005;
    int p[N] = {0};
    int t;
    cin>>t;
    int arr[t + 1][2];
    for(int i = 0;i < t;i++) {
      cin>>arr[i][0]>>arr[i][1];
    }
    primeSieve(p,N);
    for(int i = 0;i < t;i++) {
      int num = 0;
      for(int j = arr[i][0];j <= arr[i][1];j++) {
        if(p[j]) {
          num++;
        }
      }
      cout<<num<<endl;
    }
    return 0;
}
