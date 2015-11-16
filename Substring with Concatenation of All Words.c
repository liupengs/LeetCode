/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct tree{
    struct tree *child;
    struct tree *next;
    int turn;
    int atime;
    int ntime;
    char val;
};
struct tree *create(char t){
    struct tree *temp;
    temp=(struct tree *)malloc(sizeof(struct tree));
    temp->child=NULL;
    temp->next=NULL;
    temp->turn=0;
    temp->atime=0;
    temp->val=t;
    return temp;
}
struct tree *insert(char** words, int wordsSize,int len){
    int i,j;
    char t;
    struct tree *head,*temp,*temp1;
    head=create(' ');
    for(i=0;i<wordsSize;i++){
        temp=head;
        for(j=0;j<len;j++){
            t=words[i][j];
            temp1=temp->child;
            while(temp1!=NULL){
                if(temp1->val==t) break;
                else temp1=temp1->next;
            }
            if(temp1==NULL){
                temp1=create(t);
                temp1->next=temp->child;
                temp->child=temp1;
            }
            if(j+1==len){
                temp1->atime+=1;
            }
            temp=temp1;
        }
    }
    return head;
}
bool isIn(char *s,struct tree *head,int turn,int start, int len){
    int i;
    char t;
    struct tree *temp;
    temp=head->child;
    for(i=0;i<len;i++){
        t=s[start+i];
        while(temp!=NULL && temp->val!=t) temp=temp->next;
        if(temp==NULL) return false;
        if(i+1==len){
            if(temp->child==NULL){
                if(temp->turn==turn && temp->ntime>0){
                    temp->ntime--;
                    return true;
                }else if(temp->turn!=turn){
                    temp->turn=turn;
                    temp->ntime=temp->atime-1;
                    return true;
                }
            }
        }
        temp=temp->child;
    }
    return false;
}
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    struct tree *head;
    int lens=strlen(s),lenw=strlen(words[0]),i,j,t,num,*re=NULL,k=0,t1;
    if(wordsSize==0) return NULL;
    head=insert(words,wordsSize,lenw);
    t=lens-lenw*wordsSize+1;
    re=(int *)calloc(lens,sizeof(int));
    for(i=0;i<t;i++){
        num=wordsSize;
        t1=i+lenw*wordsSize;
        for(j=i;j<t1;j+=lenw){
            if(isIn(s,head,i+1,j,lenw)){
                num--;
            }else{
                break;
            }
        }
        if(num==0 && j==t1){
            re[k++]=i;
        }
    }
    (*returnSize)=k;
    return re;
}
