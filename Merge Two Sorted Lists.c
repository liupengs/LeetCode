/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head=NULL,*now,*t;
    while(l1!=NULL && l2!=NULL){
        if(l1->val<l2->val){
            t=l1;
            l1=l1->next;
        }else{
            t=l2;
            l2=l2->next;
        }
        if(head==NULL){
            head=t;
        }else{
            now->next=t;
        }
        t->next=NULL;
        now=t;
    }
    while(l1!=NULL){
        if(head==NULL){
            head=l1;
        }else{
            now->next=l1;
        }
        now=l1;
        l1=l1->next;
        now->next=NULL;
    }
    while(l2!=NULL){
        if(head==NULL){
            head=l2;
        }else{
            now->next=l2;
        }
        now=l2;
        l2=l2->next;
        now->next=NULL;
    }
    return head;
}
