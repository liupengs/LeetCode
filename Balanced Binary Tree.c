int height(struct TreeNode* root){
    int t1,t2;
    if(root==NULL) return 0;
    t1=height(root->left);
    t2=height(root->right);
    if(t1<0 || t2<0 ||  abs(t1-t2)>1) return -1;
    else return (t1>t2?t1:t2)+1;
}
bool isBalanced(struct TreeNode* root) {
    if (height(root)==-1) return false;
    else return true;
}
