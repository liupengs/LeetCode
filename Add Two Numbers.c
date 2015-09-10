/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *t1,*t2,*r=NULL,*temp,*now;
    int t=0;
    t1=l1;
    t2=l2;
    while(t1!=NULL && t2!=NULL){
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        t+=t1->val+t2->val;
        temp->val=t%10;
        t/=10;
        t1=t1->next;
        t2=t2->next;
        if(r==NULL){
            r=temp;
        }else{
            now->next=temp;
        }
        now=temp;
    }
    if(t1!=NULL){
        while(t1!=NULL){
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        t+=t1->val;
        temp->val=t%10;
        t/=10;
        t1=t1->next;
        if(r==NULL){
            r=temp;
        }else{
            now->next=temp;
        }
        now=temp;
        }
    }else if(t2!=NULL){
        while(t2!=NULL){
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        t+=t2->val;
        temp->val=t%10;
        t/=10;
        t2=t2->next;
        if(r==NULL){
            r=temp;
        }else{
            now->next=temp;
        }
        now=temp;
        }
    }
    if(t>0){
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        temp->val=t;
        if(r==NULL){
            r=temp;
        }else{
            now->next=temp;
        }
        now=temp;
    }
    return r;
}
