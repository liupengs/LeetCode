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
