int* grayCode(int n, int* returnSize) {
    int i,j,rs=pow(2,n),*results,t=2,s=2;
    results=(int *)calloc(rs,sizeof(int));
    if(n>0) results[1]=1;
    for(i=1;i<n;i++,t*=2){
        for(j=s-1;j>=0;j--) results[s++]=t+results[j];
    }
    (*returnSize)=rs;
    return results;
}
