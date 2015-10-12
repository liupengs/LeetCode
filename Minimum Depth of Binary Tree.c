int minDepth(struct TreeNode* root) {
    int deep=1,t1=999999,t2=999999;
    if(root==NULL) return 0;
    else if(root->left==NULL && root->right==NULL) return 1;
    t1=minDepth(root->left);
    t1=t1==0?999999:t1+1;
    t2=minDepth(root->right);
    t2=t2==0?999999:t2+1;
    return t1<t2?t1:t2;
}
