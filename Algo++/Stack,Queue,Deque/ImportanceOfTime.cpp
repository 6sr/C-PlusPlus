//Abhishek
//There are N processes to be completed. All the processes have a unique number assigned to them from 1 to N.

//Now, we are given two things:
//1)The calling order in which all the processes are called.
//2)The ideal order in which all the processes should have been executed.

//Executing a process takes 1 unit of time. Changing the position takes 1 unit of time.

//We have to find out the unit of time required to complete all the process such that a process is executed from the ideal
//order only when it exists at the same index in the calling order. We can push the first term from the calling order to the 
//last thus rotating the order.

#include<iostream>
#include<stack>
#include<deque>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[100],b[100];
	deque<int>dq;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		dq.push_back(a[i]);

	}
	for(int i=0;i<n;i++)
		cin>>b[i];
	int time=0;
	int i=0;
	while(i!=n)
	{
		if(dq.front()==b[i])
		{
			time+=1;
			dq.pop_front();
			i++;
		}
		else
		{
			int ele = dq.front();
			dq.pop_front();
			dq.push_back(ele);
			time+=1;
		}
	}
	cout<<time;
	return 0;

}
