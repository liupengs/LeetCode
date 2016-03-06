bool isBadVersion(int version);
int firstBadVersion(int n) {
    int s=0,t,first=n;
    while(s<=n){
        t=(s+n)/2;
        if(isBadVersion(t)){
            first=first<t?first:t;
            n=t-1;
        }else s=t+1;
    }
    return first;
}
