/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int now=0,*a=NULL;
 void vist(struct TreeNode* root, int t){
     if(root==NULL) return;
     if(t==now){
         a=(int *)realloc(a,sizeof(int)*(now+1));
         a[now]=root->val;
         now++;
     }
     if(root->right!=NULL) vist(root->right,t+1);
     if(root->left!=NULL) vist(root->left,t+1);
 }
int* rightSideView(struct TreeNode* root, int* returnSize) {
    now=0;
    a=NULL;
    vist(root,0);
    *returnSize = now;
    return a;

}
