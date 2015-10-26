char ***re=NULL;
int now;
bool checkc(int n,char temp[n][n],int r,int c){
    int i,j;
    i=r-1;
    j=c-1;
    while(i>=0 && j>=0){
        if(temp[i][j]=='Q') return true;
        i--;
        j--;
    }
    i=r-1;
    j=c+1;
    while(i>=0 &&  j<n){
        if(temp[i][j]=='Q') return true;
        i--;
        j++;
    }
    return false;
}
void solve(int n,int i,char te[n][n], char line[n]){
    int j,k,g;
    char **temp;
    if(i>=n) return;
    for(j=0;j<n;j++){
        if(line[j]=='Q' || checkc(n,te,i,j)) continue;
        else{
            if(i<n-1){
                line[j]='Q';
                te[i][j]='Q';
                solve(n,i+1,te,line);
                line[j]='.';
                te[i][j]='.';
            }else if(i==n-1){
                now++;
                re=(char ***)realloc(re,now*(sizeof(char **)));
                temp=(char **)malloc(sizeof(char *)*n);
                for(k=0;k<n;k++){
                    temp[k]=(char *)malloc(sizeof(char)*(n+1));
                    for(g=0;g<n;g++) temp[k][g]=te[k][g];
                    temp[k][n]=0;
                }
                temp[n-1][j]='Q';
                re[now-1]=temp;
            }
        }
    }
}
char*** solveNQueens(int n, int* returnSize) {
    char temp[n][n],line[n];
    re=NULL;
    now=0;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) temp[i][j]='.';
        line[i]='.';
    }
    solve(n,0,temp,line);
    (*returnSize)=now;
    return re;
}
