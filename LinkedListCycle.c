/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* temp, *last=NULL,*first;
    if(head==NULL) return false;
    first=head;
    last=head;
    head=head->next;
    last->next=NULL;
    while(head!=NULL){
        if(head==first) return true;
        else{
            temp=head->next;
            head->next=last;
            last=head;
            head=temp;
        }
    }
    return false;
}
