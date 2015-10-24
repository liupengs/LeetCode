int mySqrt(int x) {
    int s,e,t,t1;
    s=1;
    e=46340;
    if(x<1) return 0;
    while(s<e){
        t=(s+e)/2;
        t1=t*t;
        if(t1==x) return t;
        else if(t1>x) e=t-1;
        else if(t1<x && (t+1)*(t+1)>x)  return t;
        else if((t+1)*(t+1)==x) return t+1;
        else s=t+1;
    }
    return s;
}
