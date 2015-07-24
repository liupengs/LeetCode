#define min(a,b) (a)>(b)?(b):(a)
int minDistance(char* word1, char* word2) {
    int n=strlen(word1),m=strlen(word2),i,j,dis[n+1][m+1];
    if(n==0 || m==0) return n+m;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dis[i][j]=10000000;
    dis[0][0]=0;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
        {
            if(i>0) dis[i][j] = min(dis[i][j],dis[i-1][j]+1);
            if(j>0) dis[i][j] = min(dis[i][j],dis[i][j-1]+1);
            if(i>0 && j>0) dis[i][j] = word1[i-1]!=word2[j-1]?min(dis[i][j],dis[i-1][j-1]+1):min(dis[i][j],dis[i-1][j-1]);
        }
    return dis[n][m];
}
