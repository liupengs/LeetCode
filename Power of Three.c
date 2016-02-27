bool isPowerOfThree(int n) {
    int i,t,temp[22]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467,3486784401,10460353203};
    for(i=0;i<22;i++){
        t=temp[i];
        if(n<t) return false;
        else if(n==t) return true;
    }
    return false;
}
