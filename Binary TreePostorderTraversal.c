int *a=NULL,sum=0;
void travl(struct TreeNode* root){
    if(root==NULL) return;
    if(root->left!=NULL) travl(root->left);
    if(root->right!=NULL) travl(root->right);
    sum++;
    a=(int *)realloc(a,sizeof(int)*sum);
    a[sum-1]=root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    a=NULL;
    sum=0;
    travl(root);
    *returnSize=sum;
    return a;
}
