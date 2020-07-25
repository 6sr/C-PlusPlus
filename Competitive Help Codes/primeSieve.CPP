// https://ide.codingblocks.com/s/14237

#include <iostream>
using namespace std;

//PRIME SIEVE & OPTIMISATIONS


void primeSieve(int *p,int n){

    p[0] = p[1] = 0;
    p[2] = 1;

    //Let us Mark all Odd Numbers as Prime(Initialisations)
    for(int i=3;i<=n;i+=2){
        p[i] = 1;
    }

    //Sieve Login to mark non prime numbers as 0
    //1. Optimsation : Iterate only over odd Numbers
    for(int i=3;i<=n;i+=2){
        
        if(p[i]){
            //Mark all the multiples of that number as not prime.
            //2. Optimisation Take a jump of 2i starting from i*i
            for(int j=i*i;j<=n;j+=2*i){
                p[j] = 0;
            }
        }

    }
    return;
}

int main() {
    const int N = 1000000;      //const added by me to avoid error here
    int p[N] = {0};
    primeSieve(p,100);
    for(int i=0;i<=100;i++){
        if(p[i]){
            cout<<i<<" ";
        }
    }
}



//printing nth prime no
/*
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
    ll N = 100000000;
    int p[N] = {0};
    ll k = 0;
    ll req;
    cin>>req;
    primeSieve(p,N);
    for(ll i=0;i<=N;i++){
        if(p[i]){
            k++;
            if(k == req) {
                cout<<i;
            }
        }
    }
    return 0;
}
*/