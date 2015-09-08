/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int len(struct ListNode* head)
{
    struct ListNode* temp;
    int sum=0;
    temp=head;
    while(temp!=NULL){
        sum++;
        temp=temp->next;
    }
    return sum;
}
bool isPalindrome(struct ListNode* head) {
    struct ListNode* temp, *last=NULL;
    int lens,l;
    lens=len(head);
    if(lens==0) return true;
    if(lens==1) return true;
    l=lens/2;
    last=NULL;
    while(l>0){
        temp=head->next;
        head->next=last;
        last=head;
        head=temp;
        l--;
    }
    temp=last;
    if(lens%2!=0){
        head=head->next;
    }
    while(temp!=NULL){
        if(temp->val!=head->val) return false;
        temp=temp->next;
        head=head->next;
    }
    return true;
}
