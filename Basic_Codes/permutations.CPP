#include<iostream>
using namespace std;
int cnt = 0;
void permutate(char *in,int i) {
    //Base case
    if(in[i] == '\0') {
        cout<<in<<endl;
        cnt++;
        return;
    }
    //Rec case
    for(int j = i;in[j] != '\0';j++) {
        swap(in[i],in[j]);
        permutate(in,i + 1);
        //Backtracking
        swap(in[i],in[j]);
    }
}

int main() {
    char in[100];
    cin>>in;
    cout<<"Permutations : "<<endl;
    permutate(in,0);
    cout<<"Count : "<<cnt;
    return 0;
}