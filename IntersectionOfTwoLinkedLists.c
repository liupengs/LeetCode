/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int listlen(struct ListNode *head){
     struct ListNode *temp;
     int len=0;
     temp=head;
     while(temp!=NULL){
         len++;
         temp=temp->next;
     }
     return len;

 }
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int len1,len2,lent;
    struct ListNode *temp1,*temp2;
    len1=listlen(headA);
    len2=listlen(headB);
    if(len2==0 || len1==0) return NULL;
    temp1=headA;
    temp2=headB;
    if(len1<len2){
        temp1=headB;
        temp2=headA;
        lent=len2;
        len2=len1;
        len1=lent;
    }
    while(len1>len2){
        temp1=temp1->next;
        len1--;
    }
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val==temp2->val) return temp1;
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==NULL) return NULL;
    }
    return temp1;
}
