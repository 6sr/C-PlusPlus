//Abhishek got 100
//You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
//A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.

#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
int main()
{
    ll a[1000005],prefixsum[1000005];//prefixsum array is storing the frequency;
   
    int t;
    cin>>t;
    while(t--)
    {
        ll n,sum=0;
        cin>>n;
        //initializing prefixsum array.
         for(ll i=0;i<1000005;i++)
         prefixsum[i]=0;
         prefixsum[0]=1;

        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            sum%=n;
            sum =(sum+n)%n;
            prefixsum[sum]++;
        }
        ll ans=0;
        for(int j=0;j<=n-1;j++)
        {
            ll no=prefixsum[j];
            ans+=(no*(no-1))/2;

        }
        cout<<ans<<endl;
    }
    return 0;
}
