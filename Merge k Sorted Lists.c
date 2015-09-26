/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* combin(struct ListNode** lists,int s, int e){
    struct ListNode *one,*two,*head=NULL,*now,*temp;
    if(s>e){
        return NULL;
    }else if(s==e){
        one=lists[s];
        two=NULL;
    }else {
        one=combin(lists,s,(s+e)/2);
        two=combin(lists,(s+e)/2+1,e);
    }
    while(one!=NULL && two!=NULL){
        if(one->val<=two->val){
            temp=one;
            one=one->next;
        }else{
            temp=two;
            two=two->next;
        }
        if(head==NULL){
            head=temp;
        }else{
            now->next=temp;
        }
        now=temp;
        now->next=NULL;
    }
    temp=(one==NULL?two:one);
    while(temp!=NULL){
        if(head==NULL){
            head=temp;
        }else{
            now->next=temp;
        }
        now=temp;
        temp=temp->next;
        now->next=NULL;
    }
    return head;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i,mark=1,t,min;
    struct ListNode *head=NULL,*now;
    if(listsSize==0) return NULL;
    else  return combin(lists,0,listsSize-1);
}
