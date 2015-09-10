/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *a,i,j,t=0,rs,re,cs,ce;
    a=(int *)malloc(sizeof(int)*(matrixRowSize*matrixColSize));
    i=j=rs=cs=0;
    re=matrixRowSize-1;
    ce=matrixColSize-1;
    while(t<matrixRowSize*matrixColSize){
        while(j<=ce && rs<=re){
            a[t]=matrix[rs][j];
            t++;
            j++;
        }
        rs++;
        i=rs;
        while(i<=re && ce>=cs){
            a[t]=matrix[i][ce];
            t++;
            i++;
        }
        ce--;
        j=ce;
        while(j>=cs && re>=rs){
            a[t]=matrix[re][j];
            t++;
            j--;
        }
        re--;
        i=re;
        while(i>=rs && cs<=ce){
            a[t]=matrix[i][cs];
            t++;
            i--;
        }
        cs++;
        j=cs;
    }
    return a;
}
