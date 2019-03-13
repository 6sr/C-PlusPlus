//You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from position (i,j), 
//down or right on the grid.
//Initially rat is on the position (1,1). It wants to reach position (N,M). Find the rightmost path through which, rat can reach 
//this position. A path is rightmost, if the rat is at position (i,j), it will always move to (i,j+1), if there exists a path
//from (i,j+1) to (N,M).
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int check=0;
void ways(char maze[][1000],int m,int n,int path[][1000],int i,int j)
{
    if(j>=n ||i>=m||maze[i][j]=='X')
        return ;
    if(i==m-1&&j==n-1)
    {
        path[i][j]=1;
        check++;
        if(check==1)
        {for(int p=0;p<m;p++)
        {
            cout<<"\n";
            for(int q=0;q<n;q++)
                cout<<path[p][q]<<" ";

        }
        cout<<"\n";
        
        }
        
        return ;
    }
    path[i][j]=1;
    if(check==1)
    return;
    ways(maze,m,n,path,i,j+1);
    if(check==1)
    return;
    ways(maze,m,n,path,i+1,j);
    if(check==1)
    return;
    path[i][j]=0;
}

int main()
{
    char maze[1000][1000];
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>maze[i][j];
    }
    int path[1000][1000]={0};
    ways(maze,m,n,path,0,0);
    
    if(check==0)
    cout<<-1;
  
    return 0;
}
