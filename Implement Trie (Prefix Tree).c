struct TrieNode {
    struct TrieNode *next[26];
    int isend;
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    int i;
    struct TrieNode *temp;
    temp=(struct TrieNode *)malloc(sizeof(struct TrieNode));
    for(i=0;i<26;i++) temp->next[i]=NULL;
    temp->isend=0;
    return temp;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    int i,lens;
    lens=strlen(word);
    struct TrieNode *temp,*temp1;
    temp=root;
    for(i=0;i<lens;i++){
        temp1=temp->next[word[i]-'a'];
        if(temp1==NULL){
            temp1=trieCreate();
            temp->next[word[i]-'a']=temp1;
        }
        if(i+1==lens) temp1->isend=1;
        temp=temp1;
    }
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    int i,lens;
    lens=strlen(word);
    struct TrieNode *temp;
    temp=root;
    for(i=0;i<lens;i++){
        temp=temp->next[word[i]-'a'];
        if(temp==NULL) return false;
        if(i+1==lens && temp->isend==1) return true;
    }
    return false;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    int i,lens;
    lens=strlen(prefix);
    struct TrieNode *temp;
    temp=root;
    for(i=0;i<lens;i++){
        temp=temp->next[prefix[i]-'a'];
        if(temp==NULL) return false;
    }
    return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    int i;
    for(i=0;i<26;i++){
        if(root->next[i]!=NULL) trieFree(root->next[i]);
    }
    free(root);
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);
