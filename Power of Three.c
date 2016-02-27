bool isPowerOfThree(int n) {
    int s=0,e=19,t,t1,temp[20]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467};
    while(s<=e){
        t=(s+e)/2;
        t1=temp[t];
        if(t1>n) e=t-1;
        else if(t1<n) s=t+1;
        else return true;
    }
    return false;
}
