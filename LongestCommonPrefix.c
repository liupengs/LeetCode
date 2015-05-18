int minlen(char** strs, int strsSize){
    int i,j,len=0,min=99999999;
    for(i=0;i<strsSize;i++){
        if(strs[i]==NULL) return 0;
        len=0;
        for(j=0;strs[i][j]!='\0';j++){
            len++;
        }
        if(len<min) min=len;
    }
    return len;
}
char* longestCommonPrefix(char** strs, int strsSize) {
    int i,len=0,mark,j=0,min;
    char *s,c;
    min=minlen(strs,strsSize);
    while(j<min){
        c=strs[0][j];
        mark=1;
        for(i=1;i<strsSize;i++){
            if(strs[i][j]!=c){
                mark=0;
                break;
            }
        }
        if(mark==1) {len++;j++;}
        else break;
    }
     s=(char *)malloc((len+1)*sizeof(char));
     for(j=0;j<len;j++) s[j]=strs[0][j];
     s[j]='\0';
     
    return s;
    
}
