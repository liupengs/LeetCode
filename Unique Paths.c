int uniquePaths(int m, int n) {
    int i;
    double sum;
    for(sum=1,i=1;i<=n-1;i++) sum*=((double)(m+i-1)/(double)i);
    return round(sum);
}
