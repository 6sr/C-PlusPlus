

void printAllPaths(node * root,int *arr,int len) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        for(int i = 0;i < len;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    arr[len++] = root->data;
    printAllPaths(root->left,arr,len);
    printAllPaths(root->right,arr,len);
    return;
}