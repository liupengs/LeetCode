char* longestPalindrome(char* s) {
    int i,j,lens=strlen(s),len;
    if(lens<=1) return s;
    int p[lens][lens],maxlen=1,start=0;
    memset(p, 0, sizeof(p));
    char *r;
    for(i=0;i<lens-1;i++){
        p[i][i]=1;
        if(s[i]==s[i+1]){
            p[i][i+1]=1;
            if(2>maxlen){
                maxlen=2;
                start=i;
            }
        }else{
            p[i][i+1]=0;
        }
    }
    p[lens-1][lens-1]=1;
    for(len=3;len<=lens;len++){
        for(i=0;i<=lens-len;i++)
        if(s[i]==s[i+len-1] && p[i+1][i+len-2]==1){
            if(len>maxlen){
                maxlen=len;
                start=i;
            }
            p[i][i+len-1]=1;
        }else{
            p[i][i+len-1]=0;
        }
    }
    r=(char *)malloc(sizeof(char)*(maxlen+1));
    for(i=0;i<maxlen;i++) r[i]=s[start+i];
    r[i]='\0';
    return r;
}
