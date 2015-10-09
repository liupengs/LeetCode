#define min(x,y) ((x)>(y)?(y):(x))
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int temp[gridRowSize][gridColSize],i,j;
    for(i=0;i<gridRowSize;i++)
        for(j=0;j<gridColSize;j++){
            if(i>0 && j>0) temp[i][j]=min(temp[i-1][j],temp[i][j-1])+grid[i][j];
            else if(i==0 && j>0) temp[0][j]=temp[0][j-1]+grid[0][j];
            else if(j==0 && i>0) temp[i][0]=temp[i-1][0]+grid[i][0];
            else if(i==0 && j==0) temp[0][0]=grid[0][0];
        }
    return temp[gridRowSize-1][gridColSize-1];
}
