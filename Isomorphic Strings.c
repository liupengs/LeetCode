bool isIsomorphic(char* s, char* t) {
    int replace[225],mark[225],i,len1,len2;
    len1=strlen(s);
    len2=strlen(t);
    if(len1!=len2) return 0;
    for(i=0;i<225;i++) {replace[i]=-1;mark[i]=0;}
    for(i=0;i<len1;i++){
        if(replace[s[i]]==-1 && mark[t[i]]==0){
            replace[s[i]]=t[i];
            mark[t[i]]=1;
        }else if(replace[s[i]]==-1 || replace[s[i]]!=(t[i])) return false;
    }
    return true;
}
