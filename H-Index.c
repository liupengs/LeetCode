//solution one
int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int hIndex(int* citations, int citationsSize) {
    int i,h;
    qsort(citations,citationsSize,sizeof(int),comp);
    for(i=citationsSize-1,h=0;i>=0;i--){
        if(citations[i]>h) h++;
    }
    return h;
}

//solution two
int hIndex(int* citations, int citationsSize) {
    int c[citationsSize+1],i,h,a;
    memset(c,0,sizeof(int)*(citationsSize+1));
    for(i=0;i<citationsSize;i++){
        if(citations[i]>=citationsSize) c[citationsSize]++;
        else c[citations[i]]++;
    }
    for(i=citationsSize,h=0,a=0;i>0;i--){
        a+=c[i];
        if(a>=i && i>h){
            h=i;
        }else if(i>a && a>=h){
            h=a;
        }
    }
    return h;
}
