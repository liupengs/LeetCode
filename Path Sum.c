/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if(root==NULL) return false;
    if(root->left && hasPathSum(root->left,sum-root->val)) return true;
    else if(root->right && hasPathSum(root->right,sum-root->val)) return true;
    else if(root->left==NULL && root->right==NULL && root->val==sum) return true;
    else return false;
}
