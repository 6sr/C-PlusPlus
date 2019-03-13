//AbhiG
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q;
	int num;
	int prime[101]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,
	73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,
	173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,
	271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,
	383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,
	491,499,503,509,521,523,541};
	stack<int> a[100000];
	stack<int> b;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		a[0].push(num);
	}
	for(int i=1;i<=q;i++)
	{
		while(!a[i-1].empty())
		{
		  if(a[i-1].top()%prime[i]==0)
		  {
		     	b.push(a[i-1].top());
		     	a[i-1].pop();
	   	  }
		  else
		  {
		  	a[i].push(a[i-1].top());
		  	a[i-1].pop();

		  }

	    }
	    while(!b.empty())
	    {
	    	cout<<b.top()<<endl;
	    	b.pop();
	    }
	}
	while(!a[q].empty())
	{
		cout<<a[q].top()<<endl;
		a[q].pop();
	}
	return 0;

}