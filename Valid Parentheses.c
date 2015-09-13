struct starck{
    char value;
    struct starck *next;
};
struct starck * init(){
    struct starck * temp;
    temp=(struct starck *)malloc(sizeof(struct starck));
    temp->next=NULL;
    return temp;
}
void append(struct starck *head,char value){
    struct starck * temp;
    temp=(struct starck *)malloc(sizeof(struct starck));
    temp->value = value;
    temp->next=head->next;
    head->next=temp;
}

char get(struct starck *head){
    if(head->next==NULL) return '*';
    return head->next->value;
}

char pop(struct starck *head){
    struct starck * temp;
    char value;
    temp=head->next;
    if(temp!=NULL){
        value=temp->value;
        head->next=temp->next;
        free(temp);
        return value;
    }else{
        return '*';
    }
}

bool empty(struct starck *head){
    if(head->next==NULL) return true;
    else return false;
}

bool isValid(char* s) {
    int lens,i;
    struct starck *head;
    char c;
    lens=strlen(s);
    if(lens%2!=0) return false;
    head=init();
    for(i=0;i<lens;i++){
        c=get(head);
        if(s[i]==')'){
            if(c!='(') return false;
            else pop(head);

        }else if(s[i]=='}'){
            if(c!='{') return false;
            else pop(head);
        }else if(s[i]==']'){
            if(c!='[') return false;
            else pop(head);
        }else{
            append(head,s[i]);
        }
    }
    if(empty(head)) return true;
    else return false;

}
