 int max=0;
 void Depth(struct TreeNode* root,int t) {
    if(root==NULL) return;
    t++;
    if(root->left==NULL && root->right==NULL){
        if(t>max) max=t;
    }else{
        Depth(root->left,t);
        Depth(root->right,t);
    }
    
}
int maxDepth(struct TreeNode *root){
    max=0;
    Depth(root,0);
    return max;
}
