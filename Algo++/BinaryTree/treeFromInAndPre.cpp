//Manal
//Complete this code
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* createTreeFromTrav(int *in,int *pre,int s,int e){
    static int i = 0;
    //Base Case
    if(s>e){
        return NULL;
    }
    //Rec Case
    node *root = new node(pre[i]);

    int index=-1;
    for(int j=s;s<=e;j++){
        if(in[j]==pre[i]){
        index = j;
        break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in,pre,s,index-1);
    root->right = createTreeFromTrav(in,pre,index+1,e);
    return root;
}

int main() {
    int n,m;
    cin>>n;
    int *in = new int[n];
    //int in[n];
    for(int i = 0 ;i < n;i++) {
        cin>>in[i];
    }
    cin>>m;
    int *pre = new int[m];
    //int pre[m];
    for(int i = 0 ;i < m;i++) {
        cin>>pre[i];
    }
    return 0;
}