#include<iostream>
using namespace std;

int findPath(char a[][10],int path[][10],int m,int n,int i,int j) {
    //Base Case
    if(i == m && j == n) {
        path[i][j] = 1;
        for(int x = 0;x <= m;x++) {
            for(int y = 0;y <= n;y++) {
                cout<<path[x][y]<<" ";
            }
            cout<<endl;
        }
        path[i][j] = 0;
        cout<<endl;
        return 1;
    }
    //Check
    if(i > m || j > n || a[i][j] == 'X') {
        return false;
    }
    //Rec Case
    int count = 0;
    path[i][j] = 1;
    count += findPath(a,path,m,n,i,j + 1);
        //return true;
    count += findPath(a,path,m,n,i + 1,j);
    //Backtracking
    path[i][j] = 0;
    return count;
}

int main() {
    int m,n;
    cin>>m>>n;
    char maze[10][10];
    int path[10][10] = {0};
    for(int i = 0;i < m;i++) {
      for(int j = 0;j < n;j++) {
        cin>>maze[i][j];
      }
    }
    if(findPath(maze,path,m - 1,n - 1,0,0) == 0) {
      cout<<"NO PATH FOUND";
    }
    return 0;
}
