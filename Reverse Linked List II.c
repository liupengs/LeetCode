/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    int i;
    struct ListNode *temp,*last=NULL,*next=NULL,*first=NULL,*second=NULL,*t,*l;
    if(n<=m) return head;
    temp=head;
    for(i=1;i<=n;i++){
        t=temp->next;
        if(i==m-1) {
            last=temp;
        }else if(i==m){
            first=temp;
        }else if(i==n){
            second=temp;
            next=temp->next;
            temp->next=l;
        }else if(i>m && i<n){
            temp->next=l;
        }
        l=temp;
        temp=t;
    }
    if(last!=NULL) last->next=second;
    if(first!=NULL)first->next=next;
    if(m==1) head=second;
    return head;
}
