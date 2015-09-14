bool find(int** matrix,int i, int s, int e, int target){
    int j;
    while(s<=e){
        j=(s+e)/2;
        if(matrix[i][j]==target) return true;
        else if(matrix[i][j]>target){
            e=j-1;
        }else if(matrix[i][j]<target){
            s=j+1;
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i;
    for(i=0;i<matrixRowSize;i++){
        if(find(matrix,i,0,matrixColSize-1,target)) return true;
    }
    return false;
}
