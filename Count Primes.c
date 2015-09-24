int countPrimes(int n) {
    int sum=0,i,j,*a,t;
    a=(int *)calloc(n,sizeof(int));
    for(i=2;i*2<n;i++){
        if(a[i]==0){
            t=i*2;
            for(j=2;t<n;j++){
                a[t]=1;
                t=i*j;
            }
        }
    }
    for(i=2;i<n;i++){
        if(a[i]==0) sum++;
    }
    
    return sum;
}
