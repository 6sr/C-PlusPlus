//Abhishek
//Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at
//positions x1,…,xN (0 <= xi <= 1,000,000,000).

//His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
//To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance 
//between any two of them is as large as possible. What is the largest minimum distance?

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,c;
	cin>>n>>c;
	int a[100000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int s=0;
	int e=n;
	int mid;
	int ans;
	int no_cow_placed;
	int last_cow_placed;
	while(s<=e)
	{
		last_cow_placed =0;
		no_cow_placed =1;
		mid = (s+e)/2;
		for(int i=1;i<n;i++)
		{
			if(a[i]-a[last_cow_placed]>=mid)
			{
				last_cow_placed=i;
				no_cow_placed++;

			}
			if(no_cow_placed==c)
				break;

		}
		if(no_cow_placed==c)
		{

			ans=mid;
			s+=1;
		}
		if(no_cow_placed<c)
		{
			e-=1;
		}

	}
	cout<<ans;
	return 0;
}
