bool isHappy(int n) {
    int sum,t1,t2,a[811];
    t1=n;
    memset(a,0,811*sizeof(int));
    if(t1<811) a[t1]=1;
    while(true){
        sum=0;
        while(t1>0){
            t2=t1%10;
            sum+=t2*t2;
            t1/=10;
        }
        if(sum==1){
            return true;
        }else if(a[sum]==1){
            return false;
        }else if(sum==n){
            return false;
        }
        a[sum]=1;
        t1=sum;
    }
}
