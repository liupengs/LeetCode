/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int **a,i,j,t=1,rs,re,cs,ce;
    a=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++) a[i]=(int *)malloc(sizeof(int)*n);
    i=j=rs=cs=0;
    ce=re=n-1;
    while(t<=n*n){
        while(j<=ce && rs<=re){
            a[rs][j]=t;
            t++;
            j++;
        }
        rs++;
        i=rs;
        while(i<=re && ce>=cs){
            a[i][ce]=t;
            t++;
            i++;
        }
        ce--;
        j=ce;
        while(j>=cs && re>=rs){
            a[re][j]=t;
            t++;
            j--;
        }
        re--;
        i=re;
        while(i>=rs && cs<=ce){
            a[i][cs]=t;
            t++;
            i--;
        }
        cs++;
        j=cs;
    }
    return a;
}
