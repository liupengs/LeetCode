/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* temp,*t,*now;
    temp=head;
    head=NULL;
    while(temp!=NULL){
        if(temp->next!=NULL){
            t=temp->next;
            temp->next=t->next;
            t->next=temp;
        }else{
            t=temp;
        }
        if(head==NULL){
            head=t;
        }else{
            now->next=t;
        }
        now=temp;
        t=temp->next;
        temp->next=NULL;
        temp=t;
    }
    return head;
}
