int lengthOfLongestSubstring(char* s) {
    int a[256],i,st,maxlen=0,lens,t;
    for(i=0;i<256;i++) a[i]=0;
    st=i=0;
    lens=strlen(s);
    while(i<lens){
        t=(int)s[i];
        a[t]++;
        if(a[t]>1){
            while(st<i){
                a[s[st]]--;
                st++;
                if(s[st-1]==t) break;
            }
        }else{
            maxlen=maxlen>i-st+1?maxlen:i-st+1;
        }
        i++;
    }
    return maxlen;
}
