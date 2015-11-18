#define MAX(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int p[matrixColSize][2],max=0,i,j,t,k,n;
    memset(p,0,sizeof(p));
    for(i=0;i<matrixRowSize;i++)
        for(j=0;j<matrixColSize;j++){
            if(matrix[i][j]=='1'){
                if(i==0) p[j][1]=1;
                else p[j][1]+=1;
                if(j==0) p[j][0]=1;
                else p[j][0]=p[j-1][0]+1;
                max=MAX(max,p[j][0]);
                max=MAX(max,p[j][1]);
                for(k=j-1,n=p[j][1];k>=0 && p[k][1]>1;k--){
                    n=min(n,p[k][1]);
                    t=(j-k+1)*n;
                    if(t>max) max=t;
                }
            }else p[j][0]=p[j][1]=0;
        }
    return max;
}
