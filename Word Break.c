bool can(char* s, int st, int len, int *temp, char** wordDict, int wordDictSize) {
    int i,j,wlen;
    if(st==len) return true;
    else if(temp[st]==-1) return false;
    for(i=0;i<wordDictSize;i++){
        wlen = strlen(wordDict[i]);
        if((st+wlen)>len) continue;
        for(j=0;j<wlen;j++){
            if(s[st+j]!=wordDict[i][j]) break;
        }
        if(j==wlen){
            if(can(s,st+j,len,temp,wordDict,wordDictSize)) return true;
            else temp[st+j]=-1;
        }
    }
    return false;
}
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int lens,i,*temp;
    lens=strlen(s);
    temp = (int *)calloc(lens,sizeof(int));
    return can(s,0,lens,temp,wordDict,wordDictSize);
}
