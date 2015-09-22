struct WordDictionary {
    int isend;
    struct WordDictionary *next[26];
};

struct WordDictionary *head,*now;

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate() {
    struct WordDictionary *temp;
    temp=(struct WordDictionary *)malloc(sizeof(struct WordDictionary));
    temp->isend=0;
    int i;
    for(i=0;i<26;i++) temp->next[i]=NULL;
    return temp;
}

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary* wordDictionary, char* word) {
    int i,lens;
    struct WordDictionary *temp,*t;
    temp=wordDictionary;
    lens=strlen(word);
    for(i=0;i<lens;i++){
        if(temp->next[word[i]-'a']==NULL){
            t=wordDictionaryCreate();
            temp->next[word[i]-'a']=t;
            temp=t;
        }else{
            temp=temp->next[word[i]-'a'];
        }
        if(i+1==lens) temp->isend=1;
    }
}
bool find(struct WordDictionary* wordDictionary, char* word, int start, int lens){
    int i,j;
    struct WordDictionary *temp,*t;
    temp=wordDictionary;
    if(temp==NULL) return false;
    if(i==lens && temp->isend==1) return true;
    for(i=start;i<lens;i++){
        if(word[i]=='.'){
            //printf("in . i=%d\n",i);
            for(j=0;j<26;j++){
                t=temp->next[j];
                if(i+1==lens && t!=NULL && t->isend==1) return true;
                else if (find(t,word,i+1,lens)) return true;
            }
            return false;

        }else{
            printf("in 2\n");
            temp=temp->next[word[i]-'a'];
            if(temp==NULL){
                return false;
            }else if(i+1==lens && temp->isend==1){
               return true;

            }
        }
    }
    return false;
}

/** Returns if the word is in the data structure. A word could
    contain the dot character '.' to represent any one letter. */
bool search(struct WordDictionary* wordDictionary, char* word) {
    int lens;
    lens=strlen(word);
    if(lens<1) return false;
    return find(wordDictionary,word,0,lens);

}
/** Deallocates memory previously allocated for the data structure. */
void wordDictionaryFree(struct WordDictionary* wordDictionary) {
    struct WordDictionary *temp;
    int i;
    temp=wordDictionary;
    if(temp!=NULL){
        for(i=0;i<26;i++){
            if(temp->next[i]!=NULL) wordDictionaryFree(temp->next[i]);
        }
        free(temp);
    }
}
// Your WordDictionary object will be instantiated and called as such:
// struct WordDictionary* wordDictionary = wordDictionaryCreate();
// addWord(wordDictionary, "word");
// search(wordDictionary, "pattern");
// wordDictionaryFree(wordDictionary);
