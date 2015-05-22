/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int deep(struct TreeNode* left,struct TreeNode* right){
    if(left==NULL && right==NULL) return true;
    if(left!=NULL && right!=NULL && left->val==right->val) {
        return (deep(left->left,right->right) && deep(left->right,right->left));
    }
    else return false;
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL) return true;
    if(deep(root->left,root->right)) return true;
    else return false;
}
