//AbhiG
/*
The stock span problem is a financial problem where we have a series of N daily price quotes for a stock and we need to calculate span
of stock’s price for all N days. You are given an array of length N, where ith element of array denotes the price of a stock on ith.
Find the span of stock's price on ith day, for every 1<=i<=N.
A span of a stock's price on a given day, i, is the maximum number of consecutive days before the (i+1)th day, for which stock's price
on these days is less than or equal to that on the ith day. */
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++)
		cin>>a[i];
	stack<int>s;
	s.push(0);
	cout<<"1 ";
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[s.top()])
		{
			cout<<"1 ";
			s.push(i);

		}
		else
		{
			while(a[s.top()]<a[i])
			{
				s.pop();
				if(s.empty())
					break;

			}
			if(s.empty())
			{
				cout<<i+1<<" ";
			}
			else
			cout<<i-s.top()<<" ";
			s.push(i);

		}
	}
    cout<<"END";
	return 0;

}
