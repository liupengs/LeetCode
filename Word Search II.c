/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node{
    char value;
    char *word;
    struct node *next;
    struct node *child;
    bool isend;
}node;
struct node *create(){
    struct node *temp=NULL;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->child=NULL;
    temp->word=NULL;
    temp->isend=0;
    return temp;
}
char **re;
int size;
bool find(char** board ,int boardRowSize, int boardColSize, int i,int j,struct node *head,int d){
    int mark=1;
    char ctemp;
    struct node *temp;
    if(i<0 || i>=boardRowSize || j<0 || j>=boardColSize) return false;
    if(head->value==board[i][j]){
        if(head->isend==1) {
            size++;
            re=(char **)realloc(re,size*sizeof(char *));
            re[size-1]=head->word;
            head->isend=0;
        }
        ctemp=board[i][j];
        board[i][j]='*';
        temp=head->child;
        while(temp!=NULL){
            if(find(board,boardRowSize,boardColSize,i-1,j,temp,d+1)){
                temp->child=NULL;
            }else if(find(board,boardRowSize,boardColSize,i+1,j,temp,d+1)){
                temp->child=NULL;
            }else if(find(board,boardRowSize,boardColSize,i,j-1,temp,d+1)){
                temp->child=NULL;
            }else if(find(board,boardRowSize,boardColSize,i,j+1,temp,d+1)){
                temp->child=NULL;
            }else{
                mark=0;
            }
            temp=temp->next;
        }
        board[i][j]=ctemp;
        if(mark==1) return true;
    }
    return false;
}
char** findWords(char** board, int boardRowSize, int boardColSize, char** words, int wordsSize, int* returnSize) {
    int i,j,k,lens;
    struct node *head=NULL,*temp,*temp1;
    head=create();
    for(k=0;k<wordsSize;k++){
        lens=strlen(words[k]);
        temp=head;
        for(i=0;i<lens;i++){
            temp1=temp->child;
            while(temp1!=NULL){
                if(temp1->value==words[k][i]){
                    break;
                }
                temp1=temp1->next;
            }
            if(temp1==NULL){
                temp1=create();
                temp1->value=words[k][i];
                temp1->next=temp->child;
                temp->child=temp1;
            }
            if(i==lens-1){
                temp1->word=words[k];
                temp1->isend=1;
            }
            temp=temp1;
        }
    }
    re=NULL;
    size=0;
    temp=head->child;
    while(temp!=NULL){
        for(i=0;i<boardRowSize;i++){
            for(j=0;j<boardColSize;j++){
                if(find(board,boardRowSize,boardColSize,i,j,temp,0)){
                    goto out;
                }
            }
        }
        out:;
        temp=temp->next;
    }
    *returnSize=size;
    return re;
}
