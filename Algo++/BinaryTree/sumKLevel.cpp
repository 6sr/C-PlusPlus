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

node* build(){
  int d;
  cin>>d;
  node* root = new node(d);
  int child;
  cin>>child;
  if(child==0){
    root->left=NULL;
    root->right=NULL;
    return root;
  }
  else{
    root->left = build();
    root->right = build();
  }
}

int sumLevel(node* root, int k){
  if(root==NULL)
  return 0;
  if(k==0)
  return root->data;
  
  int sum=0;
  sum+= sumLevel(root->left, k-1);
  sum+= sumLevel(root->right, k-1);
  
  return sum;
  
}

int main() {
	
	node* root =NULL;
	root =build();
	int level;
	cin>>level;
	cout<<sumLevel(root, level);
	
	return 0;
}