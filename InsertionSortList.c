/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insert(struct ListNode* head,struct ListNode* temp){
     struct ListNode* t,*u;
     u=head;
     t=head->next;
     if(u->val>=temp->val){
         temp->next=head;
         return temp;
     }
     while(t!=NULL && t->val<temp->val){
         u=t;
         t=t->next;
     }
     u->next=temp;
     temp->next=t;
     return head;
      
 }
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *temp,*next;
    if(head==NULL) return NULL;
    
    temp=head->next;
    head->next=NULL;
    
    while(temp!=NULL){
        next=temp->next;
        temp->next=NULL;
        head=insert(head,temp);
        temp=next;
    }
    return head;
}
