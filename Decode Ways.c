solution one:
//从小到大，动态归划
int numDecodings(char* s) {
    int len,i;
    int r1 = 1, r2 = 1;
    len=strlen(s);
    if (len==0 || s[0] == '0') return 0;
    for (i = 1; i < len; i++) {
        if (s[i] == '0')  r1 = 0;
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }else r2 = r1;
    }
    return r1;
}

solution two:
//从大到小，动态归划
int *d;
void numbers(char *s,int start,int len){
    if(start==len) return;
    else if(start+1==len){
        if(s[start]!='0') d[start]=1;
        else d[start]=0;
    } else if(start+2==len){
        if(s[start+1]=='0') d[start+1]=0;
        else d[start+1]=1;
        if(s[start]=='0') d[start]=0;
        else if(s[start]=='1' || s[start]=='2' && s[start+1]<'7') {
            d[start]=1+d[start+1];
        }else d[start]=d[start+1];
    }else{
        if(d[start+1]==-1) numbers(s,start+1,len);
        if(d[start+2]==-1) numbers(s,start+2,len);
        if(s[start]=='0') d[start]=0;
        else if(s[start]=='1' || s[start]=='2' && s[start+1]<'7'){
            d[start]=d[start+1]+d[start+2];
        }else{
            d[start]=d[start+1];
        }
    }
}
int numDecodings(char* s) {
    int i,len;
    len=strlen(s);
    if(len==0 || s[0]=='0') return 0;
    d=(int *)malloc((len+1)*sizeof(int));
    for(i=0;i<len;i++){
        d[i]=-1;
    }
    d[len]=0;
    numbers(s,0,len);
    return d[0];
}
