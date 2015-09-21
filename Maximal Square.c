int min(int a,int b,int c){
    if(a>b) a=b;
    if(a>c) a=c;
    return a;
}
int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int **t,i,j,max;
    t=(int **)malloc(sizeof(int *)*matrixRowSize);
    for(i=0;i<matrixRowSize;i++) {
        t[i]=(int *)malloc(sizeof(int)*matrixColSize);
        for(j=0;j<matrixColSize;j++) t[i][j]=matrix[i][j]-'0';
    }
    max=0;
    for(i=0;i<matrixRowSize;i++)
        for(j=0;j<matrixColSize;j++){
            if(t[i][j]==1 && i>0 && j>0){
                t[i][j]=min(t[i-1][j-1],t[i-1][j],t[i][j-1])+1;
                if(t[i][j]>max) max=t[i][j];
            }else if(t[i][j]==1 && max<1){
                max=1;
            }
        }
    return max*max;
    
}
