int strStr(char* haystack, char* needle) {
    int len1,len2,i,j,start,t;
    len1=strlen(haystack);
    len2=strlen(needle);
    if(len1<len2) return -1;
    else if(len1==0 && len1==len2) return 0;
    else t=len1-len2;
    for(i=0;i<=t;i++){
        for(j=0;j<len2;j++){
            if(haystack[i+j]!=needle[j]) break;
        }
        if(j==len2) return i;
    }
    return -1;
}
