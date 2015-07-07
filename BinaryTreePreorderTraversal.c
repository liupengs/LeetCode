int *returns=NULL;
int Traversal(struct TreeNode* root, int nums){
    if (root!=NULL){
        nums++;
        returns=(int *)realloc(returns,nums*sizeof(int));
        returns[nums-1]=root->val;
        nums=Traversal(root->left, nums);
        nums=Traversal(root->right, nums);
    }
    return nums;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    if(root!=NULL) returns=(int *)malloc(sizeof(int));
    (* returnSize)=Traversal(root,0);
    return returns;
}
