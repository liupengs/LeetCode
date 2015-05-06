#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      struct ListNode *next;
  }ListNode;



void print(struct ListNode* temp){

    while(temp!=NULL){

        printf("%d ",temp->val);
        temp=temp->next;
        }
        printf("\n");

}

 int removelist(struct ListNode *temp,int n){
     int deep;

     if(temp==NULL) deep=0;
     else deep=removelist(temp->next,n)+1;
     if(deep==(n+1)){
         if(deep>1) temp->next=temp->next->next;
         else temp->next=NULL;
     }
     return deep;
 }
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
      struct  ListNode *temp;
        int deep;
        temp=head;
        deep=removelist(temp,n);
        if(deep==n){
            head=head->next;
        }
        return head;

}

int main()
{
    int len,n,i,v;
    struct ListNode *temp,*head=NULL,*now;
    scanf("%d",&len);
    for(i=0;i<len;i++){
        scanf("%d",&v);
        temp=(struct ListNode *)malloc(sizeof(ListNode));
        temp->next=NULL;
        temp->val=v;
        if(head==NULL){
            head=temp;
            now=temp;

        }else{
            now->next=temp;
            now=temp;
        }
    }
    while(1){
        scanf("%d",&n);
        head=removeNthFromEnd(head, n) ;
        temp=head;
        while(temp!=NULL){

        printf("%d ",temp->val);
        temp=temp->next;
        }
        printf("\n");

    }
    return 0;
}
