/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *last,*start,*end,*temp,*t,*l;
    int num;
    temp=head;
    head=NULL;
    while(1){
        start=temp;
        num=0;
        while(start!=NULL && num<k){
            num++;
            start=start->next;
        }
        if(num==k){
            start=temp;
            t=start->next;
            l=start;
            end=start;
            num=1;
            while(num<k){
                end=t;
                t=t->next;
                end->next=l;
                l=end;
                num++;
            }
            temp=t;
            start->next=NULL;
            if(head==NULL){
                head=end;
            }else{
                last->next=end;
            }
            last=start;
        }else{
            if(head==NULL){
                head=temp;
            }else{
                last->next=temp;
            }
            break;
        }
    }
    return head;
}
