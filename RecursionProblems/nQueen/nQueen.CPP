#include<iostream>
using namespace std;

int c = 0;
bool isSafe(int board[][10],int n,int x,int y) {
    
    //Column
    for(int k = 0;k < n;k++) {
        if(board[k][y] == 1) {
            return false;
        }
    }
    //Left Diag
    int i = x,j = y;
    while(i >= 0 && j >= 0) {
        if(board[i][j] == 1) {
            return false;
        }
        i--;j--;
    }
    //Right Diag
    i = x,j = y;
    while(i >= 0 && j < n) {
        if(board[i][j] == 1) {
            return false;
        }
        i--;j++;
    }
    
    return true;



    /*
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(board[i][j] == 1 && (i - j == x - y || i + j == x + y || j == y))
                return false;
        }
        return true;
    }
    */
}
bool placeQueen(int n,int board[][10],int i) {
    //Base case 
    if(i == n) {    //if i at nth row
        for(int x = 0;x < n;x++) {
                for(int y = 0;y < n;y++)
                    cout<<board[x][y];
                cout<<endl;
        }
        c++;
        cout<<endl;
        return true;
    }
    //Rec case
    int cnt = 0;
    for(int x = 0;x < n;x++) {  //placing at every column in ith row
        if(isSafe(board,n,i,x)) {
            board[i][x] = 1;
            int f = placeQueen(n,board,i + 1);
            cnt += f;
            //if(f) {
              //  return true;
            //}
            //Bakctracking
            board[i][x] = 0;
        }
    }
    //cout<<"Count "<<cnt;
    return cnt;
}

int main() {
    int board[10][10] = {0};
    int n;
    cin>>n;
    int i = 0;
    cout<<"Count "<<placeQueen(n,board,i);
    cout<<endl<<c;
    return 0;
}