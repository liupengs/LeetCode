/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *less,*greater,*root,*now,*temp;
     less=NULL;
     greater=NULL;
     root=NULL;
     while(head!=NULL){
         temp=head->next;
         head->next=NULL;
         if(head->val<x){
             if(root==NULL) root=head;
             else less->next=head;
             less=head;
         }else{
             if(greater==NULL) greater=head;
             else now->next=head;
             now=head;
         }
         head=temp;
     }
     if(root==NULL) root=greater;
     else less->next=greater;
     return root;
}
