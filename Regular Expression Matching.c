int **mark;
bool canBeZear(char *p,int s,int len){
    if(s==len) return true;
    else if((s+1)==len){
        if(p[s]=='*') return true;
        else return false;
    }else{
        if(p[s]=='*') return canBeZear(p,s+1,len);
        else if(p[s+1]=='*') return canBeZear(p,s+2,len);
        else return false;
    }
}
bool Match(char *s,char *p,int ss,int sp,int lens, int lenp){
    if(mark[ss][sp]==1) return true;
    else if(mark[ss][sp]==-1) return false;

    if(ss==lens && lenp==sp) mark[ss][sp]=1;
    else if(lens!=ss && lenp==sp) mark[ss][sp]=-1;
    else if(lens==ss && lenp!=sp ){
        if(canBeZear(p,sp,lenp)) mark[ss][sp]=1;
        else mark[ss][sp]=-1;
    }
    if(mark[ss][sp]==1) return true;
    else if(mark[ss][sp]==-1) return false;

    if(p[sp]==s[ss] || p[sp]=='.'){
        if(sp+1==lenp || p[sp+1]!='*'){
            if(Match(s,p,ss+1,sp+1,lens,lenp)){
                mark[ss][sp]=1;
            }else{
                mark[ss][sp]=-1;
            }
        }else{
            if(Match(s,p,ss+1,sp,lens,lenp)){
                mark[ss][sp]=1;
            }else if(Match(s,p,ss+1,sp+2,lens,lenp)){
                mark[ss][sp]=1;
            }else if(Match(s,p,ss,sp+2,lens,lenp)){
                mark[ss][sp]=1;
            }else{
                mark[ss][sp]=-1;
            }
        }
    }else if(p[sp]=='*'){
        mark[ss][sp]=-1;
    }else if(p[sp]!=s[ss] && sp+1<lenp && p[sp+1]=='*'){
        if(Match(s,p,ss,sp+2,lens,lenp)){
            mark[ss][sp]=1;
        }else{
            mark[ss][sp]=-1;
        }
    }else{
        mark[ss][sp]=-1;
    }
    if(mark[ss][sp]==1) return true;
    else return false;
}
bool isMatch(char* s, char* p) {
    if(strcmp(p,".*")==0) return true;
    int lens,lenp,i;
    lens=strlen(s);
    lenp=strlen(p);
    mark=(int **)malloc(sizeof(int *)*(lens+1));
    for(i=0;i<=lens;i++) mark[i]=(int *)calloc(lenp+1,sizeof(int));
    return Match(s,p,0,0,lens,lenp);
}
