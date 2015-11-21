/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* now;
void mflatten(struct TreeNode* root) {
    struct TreeNode *right=NULL;
    if(root==NULL) return;
    right=root->right;
    if(now!=NULL) now->right=root;
    now=root;
    mflatten(root->left);
    root->left=NULL;
    mflatten(right);
}
void flatten(struct TreeNode* root) {
    now=NULL;
    mflatten(root);
}
