int trip(char *s,int len){
    int i=0,mark=0,j=0;
    while(i<len && s[i]==' '){
        i++;
    }
    while(i<=len){
        s[j]=s[i];
        i++;
        j++;
    }
    return j-1;
}
int itrip(char *s,int len){
    int i=0,mark=0,j=0;
    while(i<=len){
        if(s[i]!=' ' || mark==0){
            s[j]=s[i];
            if(s[i]!=' ') mark=0;
            else mark=1;
            j++;
        }
        i++;
    }
    return j-1;
}
void reverse(char *s,int st,int e){
    char t;
    for(st,e;st<e;st++,e--){
        t=s[st];
        s[st]=s[e];
        s[e]=t;
    }
}
void reverseWords(char *s) {
    int st=0,e,len;
    len=strlen(s);
    len=trip(s,len);
    reverse(s,0,len-1);
    len=trip(s,len);
    len=itrip(s,len);
    for(e=0;e<len;e++){
        if(s[e]==' '){
            if(s[e-1]!=' ') reverse(s,st,e-1);
            st=e+1;
        }
    }
    reverse(s,st,e-1);
}
