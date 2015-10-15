bool find(char **board, int boardRowSize, int boardColSize,int r,int c,char *word,int lens, int s){
    char t;
    if(r<0 || r>=boardRowSize || c<0 || c>=boardColSize) return false;
    if(board[r][c]==word[s] && board[r][c]!='*'){
        if(s+1==lens) return true;
        t=board[r][c];
        board[r][c]='*';
        if(find(board,boardRowSize,boardColSize,r-1,c,word,lens,s+1)) return true;
        if(find(board,boardRowSize,boardColSize,r+1,c,word,lens,s+1)) return true;
        if(find(board,boardRowSize,boardColSize,r,c-1,word,lens,s+1)) return true;
        if(find(board,boardRowSize,boardColSize,r,c+1,word,lens,s+1)) return true;
        board[r][c]=t;
    }
    return false;
}
bool exist(char **board, int boardRowSize, int boardColSize, char* word) {
    int lens,i,j;
    lens=strlen(word);
    
    for(i=0;i<boardRowSize;i++){
        for(j=0;j<boardColSize;j++){
            if(find(board,boardRowSize,boardColSize,i,j,word,lens,0)) {
                return true;
            }
        }
    }
    return false;
}
