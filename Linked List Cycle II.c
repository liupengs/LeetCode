/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *t1,*t2;
    t1=head;
    t2=head;
    while(t1!=NULL && t2!=NULL){
        t1=t1->next;
        t2=t2->next;
        if(t2==NULL) return NULL;
        t2=t2->next;
        if(t1==NULL || t2==NULL) return NULL;
        if(t1==t2) break;
    }
    if(t1==NULL || t2==NULL) return NULL;
    t1=head;
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    return t1;
    
}
