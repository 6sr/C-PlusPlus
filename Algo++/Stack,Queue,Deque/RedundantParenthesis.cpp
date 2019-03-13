//AbhiG
//You are given an balanced expression. You have to find if it contains duplicate parentheses or not. A set of parentheses are 
//duplicate if same subexpression is surrounded by multiple parenthesis.

#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int t;
	cin>>t;
	char a[100];
	stack<int>s;
	for(int i=0;i<t;i++)
	{
		cin>>a;
		int j=0;
		int check=0;
		while(a[j]!='\0')
		{
			if(a[j]!=')')
			{
				s.push(a[j]);
				j++;

			}
			else
			{
				if(s.top()=='(')
				{
					cout<<"Duplicate"<<endl;
					check++;
					break;
				}
				while(s.top()!='(')
					s.pop();
				s.pop();
				j++;
			}
		}
		if(check==0)
        cout<<"Not Duplicates"<<endl;
		

		while(!s.empty())
		{
			s.pop();
		}
	}
	return 0;
}
