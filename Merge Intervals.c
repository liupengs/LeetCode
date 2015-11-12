int cmp(const void *a,const void *b)
{
    struct Interval *one,*two;
    one=(struct Interval *) a;
    two=(struct Interval *) b;
    return one->start-two->start<0?-1:1;
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    struct Interval *re;
    int i,j;
    qsort(intervals,intervalsSize,sizeof(struct Interval),cmp);
    for(i=1,j=0;i<intervalsSize;i++){
        if(intervals[i].start<=intervals[j].end){
            if(intervals[i].end>intervals[j].end) intervals[j].end=intervals[i].end;
        }
        else {
            j++;
            intervals[j].start=intervals[i].start;
            intervals[j].end=intervals[i].end;
        }
    }
    if(intervalsSize>0) j++;
    (*returnSize)=j;
    return intervals;
}
