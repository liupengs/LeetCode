int sums(struct TreeNode* root,int sum){
    int all=0;
    sum=sum*10+root->val;
    if(root->left==NULL && root->right==NULL) all=sum;
    if(root->left!=NULL) all+=sums(root->left,sum);
    if(root->right!=NULL) all+=sums(root->right,sum);
    return all;
}
int sumNumbers(struct TreeNode* root) {
    if(root==NULL) return 0;
    else return sums(root,0);
}
