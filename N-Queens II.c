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
    int j;
    if(i==n){
        now++;
        return;
    } 
    for(j=0;j<n;j++){
        if(line[j]=='Q' || checkc(n,te,i,j)) continue;
        else{
            line[j]='Q';
            te[i][j]='Q';
            solve(n,i+1,te,line);
            line[j]='.';
            te[i][j]='.';
        }
    }
}

int totalNQueens(int n) {
    char temp[n][n],line[n];
    now=0;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) temp[i][j]='.';
        line[i]='.';
    }
    solve(n,0,temp,line);
    return now;
}
