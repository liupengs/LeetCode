struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL) return NULL;
    struct ListNode *temp=head->next,*last=NULL;
    int num=1,lastnum=head->val;
    while(temp!=NULL){
        if(temp->val!=lastnum){
            if(num==1){
                if(last==NULL) last=head;
                else last=last->next;
                last->val=lastnum;
            }
            lastnum=temp->val;
            num=1;
        }else num++;
        temp=temp->next;
    }
    if(num==1){
        if(last==NULL) last=head;
        else last=last->next;
        last->val=lastnum;
    }
    if(last!=NULL) last->next=NULL;
    else return NULL;
    return head;
}
