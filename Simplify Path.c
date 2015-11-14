int copys(char *path,int s,int e,int j){
    for(;s<=e;s++) path[j++]=path[s];
    return j;
}
char* simplifyPath(char* path) {
    int s=0,e=0,lens=strlen(path),j=0,d=0,a=0,i;
    if(lens>0){
        j=1;
        e=1;
        s=1;
    }
    while(e<lens){
        if(path[e]=='.'){
           d++;
        }else if(path[e]!='/'){
           a++;
        }
        if(path[e]=='/' || e+1==lens){
            if(a>0 || d>2) j=copys(path,s,e,j);
            else if(d==2){
                j-=2;
                while(j>=0){
                    if(path[j]=='/') break;
                    else j--;
                }
                j++;
                if(j<1) j=1;
            }
            s=e+1,d=0,a=0;
       }
       e++;
    }
    if(j>1) {
        if(path[j-1]=='/') path[j-1]=0;
        else if(j<lens) path[j]=0;
    }
    else if(j==1) path[j]=0;
    return path;
}
