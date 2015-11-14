//solution one
#define max(a,b) (a)>(b)?(a):(b)
char* addBinary(char* a, char* b) {
    int la,lb,i,j;
    char *re,r='0';
    la=strlen(a);
    lb=strlen(b);
    j=max(la,lb);
    re=(char *)calloc(j+2,sizeof(char));
    la--;
    lb--;
    while(la>=0 && lb>=0){
        if(a[la]=='1' && b[lb]=='1' && r=='1'){
            re[j]='1';
        }else if((a[la]=='1' && b[lb]=='1' && r=='0') || (a[la]=='1' && b[lb]=='0' && r=='1') || (a[la]=='0' && b[lb]=='1' && r=='1')){
            re[j]='0';
            r='1';
        }else if((a[la]=='1' && b[lb]=='0' && r=='0') || (a[la]=='0' && b[lb]=='1' && r=='0') || (a[la]=='0' && b[lb]=='0' && r=='1')){
            re[j]='1';
            r='0';
        }else{
            re[j]='0';
            r='0';
        }
        j--;
        la--;
        lb--;
    }
    while(la>=0 ){
        if(a[la]=='1' && r=='1'){
            re[j]='0';
            r='1';
        }else if((a[la]=='1' && r=='0') || (a[la]=='0' && r=='1')){
            re[j]='1';
            r='0';
        }else{
            re[j]='0';
            r='0';
        }
        la--;
        j--;
    }
    while(lb>=0 ){
        if(b[lb]=='1' && r=='1'){
            re[j]='0';
            r='1';
        }else if((b[lb]=='1' && r=='0') || (b[lb]=='0' && r=='1')){
            re[j]='1';
            r='0';
        }else{
            re[j]='0';
            r='0';
        }
        lb--;
        j--;
    }
    if(r!='0'){
        re[j]=r;
        j--;
    }
    re=re+(j+1);
    return re;
    
}

//solution two
#define max(a,b) (a)>(b)?(a):(b)
char* addBinary(char* a, char* b) {
    int la=strlen(a),lb=strlen(b),i,j,t;
    char *re,r='0',ra,rb;
    j=max(la,lb);
    re=(char *)calloc(j+2,sizeof(char));
    for(la--,lb--;la>=0 || lb>=0;la--,lb--){
        ra=la>=0?a[la]:'0';
        rb=lb>=0?b[lb]:'0';
        t=ra+rb+r-144;
        re[j--]=t%2+48;
        r=t/2+48;
    }
    if(r!='0') re[j--]=r;
    re=re+(j+1);
    return re;
}
