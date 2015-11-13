/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *parent,*child,*now;
    parent=root;
    child=NULL;
    
    while(parent!=NULL){
        if(parent->left && parent->right){
            parent->left->next=parent->right;
            if(child==NULL){
                child=parent->left;
                now=parent->right;
            }else{
                now->next=parent->left;
                now=parent->right;
            }
        }else if(parent->left){
            if(child==NULL){
                child=parent->left;
                now=parent->left;
            }else{
                now->next=parent->left;
                now=parent->left;
            }
            
        }else if(parent->right){
            if(child==NULL){
                child=parent->right;
                now=parent->right;
            }else{
                now->next=parent->right;
                now=parent->right;
            }
        }
        if(parent->next) parent=parent->next;
        else{parent=child;child=NULL;}
    }
}
