//Catalan No = 2nCn / (n + 1)
//No of BST formed by 1-n nos 
//bt = n! * bst

//Time complexity of searching in bst is h where h is height of tree
//logn <= h <= n
#include<iostream>
using namespace std;

class node {
public :
    int data;
    node *left;
    node *right;
    node(int d):data(d),left(NULL),right(NULL){}
    //initializing variables as list
};

//Root-L-R
void printPreOrder(node *root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<"  ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

//L-Root-R
void printInOrder(node *root) {
    if(root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<"  ";
    printInOrder(root->right);
}

//L-R-Root
void printPostOrder(node *root) {
    if(root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<"  ";
}

node * InsertInBST(node * root,int data) {
    if(root == NULL) {
        return new node(data);
    }
    if(data < root->data) {
        root->left = InsertInBST(root->left,data);
    }
    else {
        root->right = InsertInBST(root->right,data);
    }
    return root;
}

node *buildBST() {
    node *root = NULL;
    int d;
    cin>>d;
    while(d != -1) {
        root = InsertInBST(root,d);
        cin>>d;
    }
    return root;
}

bool SearchIn(node * root,int key) {
    if(root == NULL) {
        return false;
    }
    if(root->data == key) {
        return true;
    }
    if(root->data < key) {
        return SearchIn(root->right,key);
    }
    return SearchIn(root->left,key);
}

node * removeNode(node * root,int key) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data < key) {
        root->right = removeNode(root->right,key);
    }
    else if(root->data > key) {
        root->left = removeNode(root->left,key);
    }
    else {
        //0 Children
        if(root->left == NULL && root->left == NULL) {
            delete root;
            return NULL;
        }

        //1 Children
        if(root->left != NULL && root->right == NULL) {
            node * temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL) {
            node * temp = root->right;
            delete root;
            return temp;
        }

        //2 Children
        node *temp = root->right;
        if(root->left !=NULL && root->right != NULL) {
            while(temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = removeNode(root->right,root->data);
            return root;
        }
    }
}

node * balancedBST(int *arr,int low,int up) {
    node * root;
    if(low > up) {
        return NULL;
    }
    int mid = (low + up) / 2;
    root = new node(arr[mid]);      //Takecare of this while initializing objects
    //root->data = a[mid]; causes some error
    root->left = balancedBST(arr,low,mid - 1);
    root->right = balancedBST(arr,mid + 1,up);
    return root;
}

pair<node*,node*> BSTToList(node *root) {
    pair<node*,node*> p;
    if(root == NULL) {
        p.first = p.second = NULL;
        return p;
    }

    //Both NULL
    if(root->left == NULL && root->right == NULL) {
        p.first = p.second = root;
        return p;
    }

    pair<node*,node*> pright,pleft;
    //Only one is NULL
    if(root->left == NULL && root->right != NULL) {
        pright = BSTToList(root->right);
        root->right = pright.second;
        p.first = root;
        p.second = pright.second;
        return p;
    }
    if(root->left != NULL && root->right == NULL) {
        pleft = BSTToList(root->left);
        pleft.second->left = root;
        p.first = pleft.first;
        p.second = root;
        return p;
    }

    //Both are not NULL
    pright = BSTToList(root->right);
    pleft = BSTToList(root->left);
    pleft.second->right = root;
    root->right = pright.first;
    p.first = pleft.first;
    p.second = pright.second;


    /*
    p1.second = root;
    root = p2.first;
    p.first = p1.first;
    p.second = p2.second;
    */
    return p;
}

int main() {
    node *root;
    //root = buildBST();
    int arr[] {1,2,3,4,5,6,7,8};
    root = balancedBST(arr,0,7);

    cout<<endl<<"Pre : ";
    printPreOrder(root);

    cout<<endl<<"Post : ";
    printPostOrder(root);

    cout<<endl<<"In : ";
    printInOrder(root);
    cout<<endl;

    pair<node*,node*> p = BSTToList(root);
    node *temp = p.first;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->right;
    }

    /*
    int d;
    cout<<"Enter node to delete : ";
    cin>>d;
    root = removeNode(root,d);
    cout<<endl<<"In : ";
    printInOrder(root);
    */
    return 0;
}