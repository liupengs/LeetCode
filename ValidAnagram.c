bool isAnagram(char* s, char* t) {
    int a[26],i;
    
    for(i=0;i<26;i++) a[i]=0;
    
    int len1,len2;
    len1=strlen(s);
    len2=strlen(t);
    if(len1!=len2) return false;
    for(i=0;i<len1;i++){
        a[s[i]-'a']+=1;
        a[t[i]-'a']-=1;
    }
    for(i=0;i<26;i++){
        if(a[i]!=0) return false;
    }
    return true;
}
