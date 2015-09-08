/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void listsort(int *a,int start,int end){
     int t,s,e,c;
      t=a[start];
      s=start;
      c=start;
      e=end+1;
     while(s<=e){
        e--;
        while(a[e]>=t && e>c){
            e--;
        }
        if(e>c){
            a[c]=a[e];
            c=e;
        }
        s++;
        while(a[s]<=t && s<c){
            s++;
        }
        if(s<c){
            a[c]=a[s];
            c=s;
        }
     }
     a[c]=t;
     if( c-1>start) listsort(a,start,c-1);
     if( end>c+1) listsort(a,c+1,end);
 }
 int * ListLen(struct ListNode* head,int *sum){
     struct ListNode* temp;
     int *a=NULL;
     (*sum)=0;
     temp=head;
     while(temp!=NULL){
         (*sum)++;
         a=(int *)realloc(a,sizeof(int)*(*sum));
         a[(*sum)-1]=temp->val;
         temp=temp->next;
     }
     return a;
 }
struct ListNode* sortList(struct ListNode* head) {
    int sum;
    int *a,i;
    struct ListNode* temp;
    a=ListLen(head,&sum);
    if(a<2) return head;
    listsort(a,0,sum-1);
    temp=head;
    i=0;
    while(temp!=NULL){
        temp->val=a[i];
        i++;
        temp=temp->next;
    }
    return head;
}
