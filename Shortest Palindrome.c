int lastPalindrome(char *str,int len){
    int i,s,e;
    s=0;
    i=e=len-1;
    while(s<e){
        if(str[s]==str[e]){
            s++;
            e--;
        }else{
            i--;
            s=0;
            e=i;
        }
    }
    return i+1;
}
char* shortestPalindrome(char* s) {
    int len,i,j,k=0;
    char *r=NULL;
    len=strlen(s);
    r=(char *)calloc((len+len+1),sizeof(char));
    if(len<1) return r;

    i=lastPalindrome(s,len);
    for(j=len-1,k=0;j>=i;j--,k++){
        r[k]=s[j];
    }
    for(j=0;j<len;j++,k++){
        r[k]=s[j];
    }
    return r;
}
