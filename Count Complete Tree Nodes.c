/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int leftlen(struct TreeNode* root){
    struct TreeNode* temp;
    int len=0;
    temp=root;
    while(temp!=NULL){
        len++;
        temp=temp->left;
    }
    return len;
}
int rightlen(struct TreeNode* root){
    struct TreeNode* temp;
    int len=0;
    temp=root;
    while(temp!=NULL){
        len++;
        temp=temp->right;
    }
    return len;
}
int isLeftRight(struct TreeNode* root, int fool, int hight){
    struct TreeNode* temp;
    temp=root;
    while(temp!=NULL){
        if(temp->right==NULL && fool<hight-1) return 1;
        else if(temp->left==NULL && temp->right==NULL) return 0;
        temp=temp->right;
        fool++;
    }
}

int countNodes(struct TreeNode* root) {
    struct TreeNode* temp;
    int sum,left,right,i,t,r[32],mark=0,fool,hight;

    left=leftlen(root);
    right=rightlen(root);
    
    sum=(int )pow(2,(double) left)-1;
    if(left==right) return sum;
    
    hight=left;
    temp=root;
    fool=0;
    while(temp!=NULL){
        if(temp->left!=NULL && temp->right!=NULL){
            t=isLeftRight(temp->left,fool+1,hight);
        }else if(temp->left!=NULL && temp->right==NULL){
            r[fool]=1;
            fool++;
            break;
        }else if(temp->left==NULL && temp->right==NULL){
            mark=1;
            r[fool]=0;
            fool++;
            break;
        }
        if(t==1){
            temp=temp->left;
            r[fool]=1;
        }else{
            temp=temp->right;
            r[fool]=0;
        }
        fool++;
    }
    t=0;
    for(i=0;i<fool;i++){
        t=t*2+r[i];
    }
    if(mark==1) t+=2;
    return sum-t;

}
