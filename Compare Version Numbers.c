int getstr(char* version,int *a){
    int i=0,j=0,t=0,len;
    for(len=strlen(version);i<len;i++){
        if(version[i]>='0' && version[i]<='9') t=t*10+(version[i]-'0');
        else{
            a[j++]=t;
            t=0;
        }
    }
    if(version[len-1]!='.') a[j++]=t;
    return j;
}
int compareVersion(char* version1, char* version2) {
    int a[1000],b[1000],anum,bnum,i;
    memset(a,0,sizeof(int)*1000);
    memset(b,0,sizeof(int)*1000);
    anum=getstr(version1,a);
    bnum=getstr(version2,b);
    anum=anum>bnum?anum:bnum;
    for(i=0;i<=anum;i++){
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return -1;
    }
    return 0;
}
