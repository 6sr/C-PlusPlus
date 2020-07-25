#include<iostream>
using namespace std;

int findPath(char a[][10],int path[][10],int m,int n,int i,int j) {
    //Base Case
    if(i == m && j == n) {
        path[i][j] = 1;
        for(int x = 0;x <= m;x++) {
            for(int y = 0;y <= n;y++) {
                cout<<path[x][y];
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
    char maze[10][10] = {
                            "000X",
                            "0X00",
                            "00X0",
                            "000X",
                            "0X00"
    };
    int path[10][10] = {0};
    cout<<findPath(maze,path,4,3,0,0);
    cout<<"\nLOL";
    return 0;
}




/*
#include<iostream>
using namespace std;

int flag = 0;

void findPath(char a[][1005],int path[][1005],int m,int n,int i,int j) {
    //Base Case
    if(i == m && j == n && flag == 0) {
        path[i][j] = 1;
        flag = 1;
        for(int i = 0;i <= m;i++) {
          for(int j = 0;j <= n;j++) {
            cout<<path[i][j]<<" ";
          }
          cout<<endl;
        }
        path[i][j] = 0;
        //cout<<endl;
        return;
    }
    //Check
    if(i > m || j > n || a[i][j] == 'X') {
        return;
    }
    //Rec Case
    path[i][j] = 1;
    findPath(a,path,m,n,i,j + 1);
        //return true;
    findPath(a,path,m,n,i + 1,j);
    //Backtracking
    path[i][j] = 0;
}

int main() {
    char maze[1005][1005];
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < n;i++) {
      for(int j = 0;j < m;j++) {
        cin>>maze[i][j];
      }
    }
    int path[1005][1005] = {0};
    findPath(maze,path,n - 1,m - 1,0,0);
    if(flag == 0) {
      cout<<"-1";
    }
    return 0;
}
*/