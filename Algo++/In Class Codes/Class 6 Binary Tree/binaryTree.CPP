#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

class node {
public :
    int data;
    node *left;
    node *right;

    //initializing variables as list
    node(int d):data(d),left(NULL),right(NULL){}   
};

node* build() {
    int d;
    cin>>d;
    //Base Case
    if(d == -1) {
        return NULL;
    }
    //Rec Case
    node * root;
    root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}

//Root-L-R
int countNode(node* root) {
    int cnt = 0;
    if(root == NULL) {
        return 0;
    }
    cnt = cnt + countNode(root->left) + countNode(root->right) + 1;
    return cnt;
}

int sumNode(node* root) {
    int sum = 0;
    if(root == NULL) {
        return sum;
    }
    sum += root->data + sumNode(root->left) + sumNode(root->right);
    return sum;
}

int height(node* root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
}

void printK(node* root,int k) {
    if(root == NULL || k < 0) {
        return;
    }
    if(k == 1) {
        cout<<root->data<<"  ";
        return;
    }
    /*
    if(k == curr) {
        cout<<root->data;
        return;
    }
    printK(root->left,k,curr + 1);
    printK(root->right,k,curr + 1);
    */
   printK(root->left,k - 1);
   printK(root->right,k - 1);
}

void printLevelWise(node* root) {
    if(root == NULL) {
        return;
    }
    int h = height(root);
    for(int i = 1;i <= h;i++) {
        printK(root,i);
    }    
}

//Root-L-R
void printPreOrder(node* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<"  ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

//L-Root-R
void printInOrder(node* root) {
    if(root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<"  ";
    printInOrder(root->right);
}

//L-R-Root
void printPostOrder(node* root) {
    if(root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<"  ";
}

//Iteratively! ----> Breadth First Search(BFS)
void printBFS(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node * f = q.front();
        if(f == NULL) {
            cout<<endl;
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
            }
            continue;
        }
        cout<<f->data<<" ";
        q.pop();

        if(f->left) {
            q.push(f->left);
        }
        if(f->right) {
            q.push(f->right);
        }
    }
}

node * buildBFS() {
    queue<node*> q;
    node *root = NULL;
    int d;
    cin>>d;     //Enter root data
    if(d == -1) {
        return root;
    }
    root = new node(d);
    q.push(root);
    int l,r;
    while(!q.empty()) {
        cin>>l>>r;
        node * f = q.front();
        q.pop();
        if(l != -1) {
            f->left = new node(l);
            q.push(f->left);
        }
        if(r != -1) {
            f->right = new node(r);
            q.push(f->right);
        }        
    }
    return root;
}

void mirrorNode(node* root) {
    if(root == NULL) {
        return;
    }
    swap(root->left,root->right);
    mirrorNode(root->left);
    mirrorNode(root->right);
    return;
}

//Replace node data by sum of descendants and itself
int replaceSum1(node* root) {
    if(root == NULL) {
        return 0;
    }
    root->data += replaceSum1(root->left) + replaceSum1(root->right);
    return root->data;
}

//Replace node data by sum of its descendants and leaf node unchanged
int replaceSum2(node* root) {
    //Base Case
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        return root->data;
    }
    //Rec Case
    int temp = root->data;
    root->data = replaceSum2(root->left) + replaceSum2(root->right);
    return root->data + temp;
}

int diameter(node* root) {     //complexity n^2
    if(root == NULL) {
        return 0;
    }
    int op1 = height(root->left) + height(root->right);
    int op2 = max(diameter(root->left),diameter(root->right));
    return max(op1,op2);
}

//Complexity n
pair<int,int> diameterFast(node* root) {    // first is height and second is diameter
    pair<int,int> p;
    if(root == NULL) {
        p.first = p.second = 0;
        return p;
    }
    pair<int,int> left,right;
    left = diameterFast(root->left);
    right = diameterFast(root->right);

    p.first = max(left.first,right.first) + 1;

    int op1 = left.first + right.first;
    int op2 = max(left.second,right.second);
    p.second = max(op1,op2);

    return p;
}

pair<bool,int> balanced(node* root) {
    pair<bool,int> p;
    if(root == NULL) {
        p.first = true;
        p.second = 0;
        return p;
    }
    pair<bool,int> left,right;
    left = balanced(root->left);
    right = balanced(root->right);

    p.second = max(left.second,right.second) + 1;

    if(right.second - left.second <= 1 && right.second - left.second >= -1) {
        p.first = left.first && right.first;
    }
    else {
        p.first = false;
    }
    return p;
}

int oneBalanced(node* root) {
    if(root = NULL) {
        return 0;
    }
    int left = oneBalanced(root->left);
    int right = oneBalanced(root->right);
    if(left == -1 || right == -1) {
        return -1;
    }
    if(left - right >= -1 && left - right <= 1) {
        return max(left,right) + 1;
    }
    else {
        return -1;
    }
}

int main() {
    node* root;
    root = build();
    /*
    cout<<endl<<"Pre : ";
    printPreOrder(root);

    cout<<endl<<"Post : ";
    printPostOrder(root);

    cout<<endl<<"In : ";
    printInOrder(root);

    cout<<endl<<"Count : "<<countNode(root);

    cout<<endl<<"Height : "<<height(root);

    cout<<endl<<"Level Wise : ";
    printLevelWise(root);
    */

    //root = buildBFS();
    cout<<endl;
    printBFS(root);
    //mirrorNode(root);
    //cout<<endl<<"Mirror : "<<endl;
    //printBFS(root);

    cout<<"Printting kth level : ";
    printK(root,4);
    cout<<endl<<"Diameter : "<<diameter(root);
    cout<<endl<<"Height : "<<height(root);
    return 0;
}

//Sample Input
//For Build Fn   8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
//For BuildBFS Fn   8 10 3 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
/*
                            8 
            10                                  3
        1              6                 -1             14
    -1     -1      4         7                       13      -1
                -1   -1   -1   -1                 -1    -1
*/

//Binary Tree Formed
/*
                    8
        10                    3
  1             6                14
            4       7       13
*/
