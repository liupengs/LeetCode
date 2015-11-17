//solution one
int **p;
int PathNums(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize,int x,int y){
    if(x<0 || y<0) return 0;
    if(p[x][y]!=-1) return p[x][y];
    else if(obstacleGrid[x][y]=='1') p[x][y]=0;
    else if(x==0 && y==0) return p[0][0];
    else if(x==0) p[x][y]=PathNums(obstacleGrid,obstacleGridRowSize,obstacleGridColSize,x,y-1);
    else if(y==0) p[x][y]=PathNums(obstacleGrid,obstacleGridRowSize,obstacleGridColSize,x-1,y);
    else p[x][y]=PathNums(obstacleGrid,obstacleGridRowSize,obstacleGridColSize,x-1,y)+PathNums(obstacleGrid,obstacleGridRowSize,obstacleGridColSize,x,y-1);
    printf("%d %d %d\n",x,y,p[x][y]);
    return p[x][y];
}
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int i,j;
    if(obstacleGridRowSize==0 || obstacleGridColSize==0) return 0;
    p=(int **)malloc(sizeof(int *)*obstacleGridRowSize);
    for(i=0;i<obstacleGridRowSize;i++){
        p[i]=(int *)malloc(sizeof(int )*obstacleGridColSize);
        for(j=0;j<obstacleGridColSize;j++) p[i][j]=-1;
    }
    if(obstacleGrid[0][0]=='0') p[0][0]=1;
    else p[0][0]=0;
    return PathNums(obstacleGrid,obstacleGridRowSize,obstacleGridColSize,obstacleGridRowSize-1,obstacleGridColSize-1);
}

//solution two
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int i,j,p[obstacleGridColSize];
    if(obstacleGridRowSize==0 || obstacleGridColSize==0 || obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1]==1) return 0;
    for(i=0;i<obstacleGridRowSize;i++)
        for(j=0;j<obstacleGridColSize;j++){
            if(obstacleGrid[i][j]==1) p[j]=0;
            else if(i==0 && j==0) p[0]=1;
            else if(i==0) p[j]=p[j-1];
            else if(j==0) p[j]=p[j];
            else p[j]=p[j]+p[j-1];
        }
    return p[obstacleGridColSize-1];
}
