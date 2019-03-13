//AbhiG
//Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N 
//and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by
//doing exactly K swaps among a pair of the given permutation. Help him to find the final permutation.

#include<iostream>
#include<unordered_map>
#include<functional>
using namespace std;
int main()
{
	unordered_map<long,long> mp;
	long long  n,k;
	cin>>n>>k;
	int a[100000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mp[a[i]] = i;

	}
    int j=0;
    while(k>0&&j<n)
    {
        if(mp[n-j]==j)
        {
            j++;
        }
        else
        {
            int ele = a[j];
            swap(a[mp[n-j]],a[j]);
            int temp=mp[n-j];
            mp[n-j]=j;
            mp[ele]=temp;
            k--;
            j++;
            
        }
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

    return 0;
}
