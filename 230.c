int num,mark,value;
void find(struct TreeNode* root, int k){
    if(root!=NULL && mark==0){
        find(root->left,k);
        num++;
        if(num==k){
            mark=1;
            value=root->val;
        }
        find(root->right,k);
    }
}

int kthSmallest(struct TreeNode* root, int k) {
    num=0;
    mark=0;
    find(root,k);
    return value;
}
