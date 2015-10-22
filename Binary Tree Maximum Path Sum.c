/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int re;
int paths(struct TreeNode *head){
    int t1,t2,t3;
    t1=t2=0;
    if(head->left!=NULL){
        t1=paths(head->left);
    } 
    if(head->right!=NULL){
        t2=paths(head->right);
    }
    t1=t1+head->val;
    t2=t2+head->val;
    t3=t1+t2-head->val;
    t1=t1>t2?t1:t2;
    t1=t1>head->val?t1:head->val;
    if(t1>re) re=t1;
    if(t3>re) re=t3;
    //printf("%d %d %d\n",head->val,re,t1);
    return t1;
}
int maxPathSum(struct TreeNode* root) {
    re=-9999999;
    if(root==NULL) return 0;
    else paths(root);
    return re;
}
