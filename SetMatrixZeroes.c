void setZeroes(int **matrix, int m, int n) {
    int i,j,*r,*c;
    r=(int *)malloc(sizeof(int)*m);
    c=(int *)malloc(sizeof(int)*n);
    for(i=0;i<m;i++) r[i]=0;
    for(i=0;i<n;i++) c[i]=0;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(matrix[i][j]==0){
                r[i]=1;
                c[j]=1;
            }
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(r[i]==1 || c[j]==1) matrix[i][j]=0;
        }
    }
}
