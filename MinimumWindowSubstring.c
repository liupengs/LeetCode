char* minWindow(char* s, char* t) {
    int need[225],have[225],start=0,end=0,i,total=0,ms,me,mlen=9999999,t1;
    char *r=NULL;
    if(s==NULL || t==NULL  || s=="" || t=="") {
        r=(char *)malloc(sizeof(char));
        *r='\0';
        return r;
    }
    memset(need,0,225*sizeof(int));
    memset(have,0,225*sizeof(int));
    for(i=0;t[i]!='\0';i++) {
        need[t[i]]++;
        have[t[i]]++;
        total++;
    }
    while(1){
        //move end
        while(total!=0){
            if(s[end]=='\0') break;
            t1=s[end];
            if(have[t1]>0){
                need[t1]--;
                if(need[t1]>=0){
                    total--;
                }
            }
            end++;
        }
        //move start
        while(start<=end){
            t1=s[start];
            if(have[t1]>0){
                need[t1]++;
                if(need[t1]>0){
                    total++;
                    if(total==1){
                        if(end-start<mlen){
                            ms=start;
                            me=end-1;
                            mlen=end-start;
                        }
                    }
                    start++;
                    break;
                }
            }
            start++;
        }
        if(s[end]=='\0') break;
    }
    if(mlen==99999999){
        r=(char *)malloc(sizeof(char));
        r[0]='\0';
    }else{
        r=(char *)malloc((mlen+1)*sizeof(char));
        t1=0;
        for(i=ms;i<=me;i++){
            r[t1]=s[i];
            t1++;
        }
        r[t1]='\0';
    }
    return r;
}
