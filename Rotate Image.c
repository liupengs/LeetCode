void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j,k,n,t;
    matrixRowSize/=2;
    for(i=0,k=matrixColSize-1;i<matrixRowSize;i++,k-=2){
        for(j=i;j<i+k;j++){
            t=matrix[i][j];
            matrix[i][j]=matrix[matrixColSize-j-1][i];
            matrix[matrixColSize-j-1][i]=matrix[i+k][matrixColSize-j-1];
            matrix[i+k][matrixColSize-j-1]=matrix[j][i+k];
            matrix[j][i+k]=t;
        }
    }
}
