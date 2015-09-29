bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int a[10],i,j,t,k;
    for(i=0;i<9;i++){
        memset(a,0,sizeof(int)*10);
        for(j=0;j<9;j++){
            if(board[i][j]!='.'){
                t=board[i][j]-'0';
                if(a[t]==1) return false;
                else a[t]=1;
            }
        }
    }
    for(i=0;i<9;i++){
        memset(a,0,sizeof(int)*10);
        for(j=0;j<9;j++){
            if(board[j][i]!='.'){
                t=board[j][i]-'0';
                if(a[t]==1) return false;
                else a[t]=1;
            }
        }
    }
    k=0;
    for(i=0;i<9;i+=3){
        for(j=0;j<9;j+=3){
           memset(a,0,sizeof(int)*10);
           for(k=0;k<9;k++){
               if(board[i+k/3][j+k%3]!='.'){
                    t=board[i+k/3][j+k%3]-'0';
                    if(a[t]==1) return false;
                    else a[t]=1;
                }
           }
        }
    }
   return true;     
}
