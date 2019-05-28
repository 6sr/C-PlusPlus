//Piyush is lost in a magical park which contains N rows and M columns.In order to get out of park safely and return home, 
//he needs atleast K amount of strength.Given a N by M pattern, your task is to find weather Piyush can ever escape the park.

//The pattern consisits of '.' , * and '#'.Intially the strength is S and if Piyush encounters * , strength increases by 5.
//If he encounters '.', strength decreases by 2.Please note that Piyush can only walk row wise, so he starts from left of a row 
//and moves towards right and he does this for every row. If he encounters '#', this means that the row is blcked and he cannot 
//move forward. Also while moving in a row, Piyush requires strength of 1 for every step and strength should always be positive 
//for moving forward.

//Assume that Piyush can shift immediately from last of one row to the start of next one without loss of any strength, help out 
//Piyush to escape the park.

#include<iostream>
using namespace std;
int main() {
  int n,m,k,s;
  cin>>n>>m>>k>>s;
  char arr[n][m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>arr[i][j];
    }
  }
  int max1=s;
  for(int i=0;i<n;i++)
  { if(max1<=0)break;
    for(int j=0;j<m;j++)
    {
      if(max1<=0){
        break;
      }
      else if(arr[i][j]=='.'&&j==m-1)
      {
        max1=max1-2;

      }
      else if(arr[i][j]=='.' && j<m-1)
      {
          max1=max1-3;
      }
       else if(arr[i][j]=='*' && j==m-1)
      {
        max1=max1+5;
        
      }
      else if(arr[i][j]=='*' && j<m-1)
      {
          max1=max1+4;
      }
       else if(arr[i][j]=='#')
      { 
         break;
      }
    }
  }
  if(max1>=k)
  {
    cout<<"Yes"<<endl;
    cout<<max1<<endl;
  }
  else{
      cout<<"No"<<endl;
  }
	return 0;
}
