bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==q && p==NULL) return true;
    else if(p==NULL || q==NULL) return false;
    if(q->val==p->val){
        if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) return true;
        else return false;
    }else{
        return false;
    }
}
