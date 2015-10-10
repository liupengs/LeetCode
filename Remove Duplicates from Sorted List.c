/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *first,*now,*temp;
    if(head==NULL) return NULL;
    first=head;
    now=head;
    temp=head->next;
    while(temp!=NULL){
        if(temp->val!=now->val){
            now->next=temp;
            now=temp;
        }
        temp=temp->next;
        now->next=NULL;
    }
    return first;
}
