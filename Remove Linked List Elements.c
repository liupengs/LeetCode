/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode * first,*second;
    first=NULL;
    second=head;
    while(second!=NULL){
        if(second->val!=val){
            if(first==NULL) first=head;
            else first=first->next;
            first->val=second->val;
        }
        second=second->next;
    }
    if(first==NULL) head=NULL;
    else first->next=NULL;
    return head;
}
