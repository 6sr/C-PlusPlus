//Manal
//You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from a position towards 
//left, right, up or down on the grid.
//Initially rat is on the position (1,1). It wants to reach position (N,M) where it's cheese is waiting for. There exits a unique 
//path in the grid . Find that path and help the rat reach its cheese.

#include<bits/stdc++.h>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[10][10],int i,int j,int n,int m){
    if(maze[i][j]=='X'){
        return false;
    }
	
	if(i==n&&j==m){
        soln[n][m]=1;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<soln[i][j]<<" ";
        }
        cout<<endl;
    }        

        return true;
    }
    
    if(i>n||j>m||i<0||j<0){
        return false;
    }
    
    
    
    bool right,down,up,left;
    soln[i][j] = 1;
    
    if(soln[i+1][j]==0){
        down = ratInMaze(maze,soln,i+1,j,n,m);
    }
    if(soln[i][j+1]==0){
        right = ratInMaze(maze,soln,i,j+1,n,m);
    }
    if(soln[i-1][j]==0){
        up = ratInMaze(maze,soln,i-1,j,n,m);
    }
    if(soln[i][j-1]==0){
        left = ratInMaze(maze,soln,i,j-1,n,m);
    }
    
    if(right||down||left||up){
        return true;
    }
    
    soln[i][j] = 0;
    
    return false;
}


int main() {
    int n,m;
    cin>>n>>m;
    
    char maze[10][10];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    
    int soln[10][10]={0};
    
    bool ans = ratInMaze(maze,soln,0,0,n-1,m-1);
    
    if(ans==false){
        cout<<"NO PATH FOUND";
    }
    
	return 0;
}
