int hIndex(int* citations, int citationsSize) {
    int s,e,h,t;
    s=0;
    e=citationsSize-1;
    h=0;
    while(s<=e){
        t=(s+e)/2;
        if(citations[t]>=(citationsSize-t)){
            h=citationsSize-t;
            e=t-1;
        }else if(citations[t]<(citationsSize-t)){
            s=t+1;
        }
    }
    return h;
}
