int numTrees(int n) {
    int i,j,g[n+1];
    memset(g,0,sizeof(g));
    if(n>0) g[1]=1;
    for(i=2;i<=n;i++){
        g[i]=0;
        for(j=1;j<=i;j++){
            if(g[j-1]!=0 && g[i-j]!=0) g[i]+=(g[j-1]*g[i-j]);
            else g[i]+=(g[j-1]+g[i-j]);
        }
    }
    return g[n];
}
