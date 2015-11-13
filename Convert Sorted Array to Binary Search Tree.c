/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* ArrayToBST(int* nums, int s,int e){
    if(s>e) return NULL;
    struct TreeNode *temp;
    int t;
    t=(s+e)/2;
    temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val=nums[t];
    temp->left=ArrayToBST(nums,s,t-1);
    temp->right=ArrayToBST(nums,t+1,e);
    return temp;
} 
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return ArrayToBST(nums,0,numsSize-1);
}
