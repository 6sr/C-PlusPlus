//Manal
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d):data(d),left(NULL),right(NULL){}
};

class info{
    public:
    int min;
    int max;
    bool isBST;
    int size ;
    
    info(){
        min = 1000000;
        max = 0;
        isBST = true;
        size = 0;
    }
};

info largest (node* root){
        
        if(root == NULL){
            info k ;
            return k;
        }
        
        info leftMinMax = largest(root->left);
        info rightMinMax = largest(root->right);
        
        info m ;
        
        if((leftMinMax.isBST == false || rightMinMax.isBST == false || (leftMinMax.max > root->data) || rightMinMax.min <= root->data)){
            m.isBST = false;
            m.size = max(leftMinMax.size, rightMinMax.size);
            return m;
        }
        
        m.isBST = true;
        m.size = leftMinMax.size + rightMinMax.size + 1;
     
        m.min = root->left != NULL ? leftMinMax.min : root->data;
  
        //if root.right is null then set root.data as max else
        //take max of right side as max.
        m.max = root->right != NULL ? rightMinMax.max : root->data;
   
        return m;
    }


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

int main(){
    int n;
    cin>>n;
    int pre[n];
    int in[n];
    for(int j =0; j<n;j++){
        cin>>pre[j];
    }

    
    for(int i =0; i<n;i++){
        cin>>in[i];
    }

    node* root =NULL;
    root = createTreeFromTrav(in, pre, 0, n-1);
    info result = largest(root);

    cout<<result.size;

}