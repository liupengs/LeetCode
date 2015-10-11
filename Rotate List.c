/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int lens;
    struct ListNode *temp;
    temp=head;
    lens=0;
    while(temp!=NULL){
        lens++;
        if(temp->next==NULL) {
            temp->next=head;
            break;
        }else{
            temp=temp->next;
        }
    }
    if(lens==0) return NULL;
    k%=lens;
    while(lens>k){
        lens--;
        temp=head;
        head=head->next;
        if(lens==k){
            temp->next=NULL;
            break;
        }
    }
    return head;
}
