//Manal
#include <iostream>
#include <queue>
#include <map>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    int vd;
    node(int d):data(d),left(NULL), right(NULL), vd(INT8_MAX){};
};


void buildusingBFS(){

	map<int, int> m;
    node*root = NULL;
	queue<node*> q;
    int vd = 0;
	int d;
	//cout<<"Enter root data";
	cin>>d;
	root = new node(d);
    root->vd = vd;
	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		//cout<<"Enter children of "<<f->data<<endl;
        vd = f->vd;
        if(m.count(vd)==0)
        m[vd] = f->data;
		int c1,c2;
		q.pop();

		cin>>c1>>c2;
		if(c1!=-1){
			f->left = new node(c1);
            f->left->vd = vd+1; 
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
            f->right->vd = vd+1;
			q.push(f->right);
		}
	}

    for(auto i=m.begin(); i!=m.end();i++){
        cout<<i->second<<" ";
    }
	return ;
}



int main() {
    buildusingBFS();
    //cout<<"Hello World!";
}
