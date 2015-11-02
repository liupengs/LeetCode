
int climbStairs(int n) {
    int i,t1=1,t2=2;
    if(n==1) return 1;
    else if(n==2) return 2;
    for(i=2;i<n;i++){
        t2=t1+t2;
        t1=t2-t1;
    }
    return t2;
}
