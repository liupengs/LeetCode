/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
   int i,j,s,e;
    struct Interval* re;
    re=NULL;
    re=(struct Interval*)malloc(sizeof(struct Interval)*(intervalsSize+1));
    if(intervalsSize==0){
        *returnSize=1;
        re[0].start=newInterval.start;
        re[0].end=newInterval.end;
        return re;
    }
   i=j=0;
   s=e=0;
   while(i<intervalsSize){
       if(intervals[i].end<newInterval.start || intervals[i].start>newInterval.end){
            if(intervals[i].start>newInterval.end && e==0){
                if(s==0) {
                    re[j].start=newInterval.start;
                    s=1;
                }
                if(e==0){
                    re[j].end=newInterval.end;
                    e=1;
                    j++;
                }
            }
            re[j].start=intervals[i].start;
            re[j].end=intervals[i].end;
            j++;
        }else{
            if(s==0 && newInterval.start<=intervals[i].start){
                re[j].start=newInterval.start;
                s=1;
            }else if(s==0 && newInterval.start<=intervals[i].end){
                re[j].start=intervals[i].start;
                s=1;
            }
            if(e==0 && newInterval.end<=intervals[i].end){
                re[j].end=intervals[i].end;
                e=1;
                j++;
            }
        }
        i++;
   }
   if(s==0 && e==0){
       re[j].start=newInterval.start;
       re[j].end=newInterval.end;
       j++;
   }else if(e==0){
       re[j].end=newInterval.end;
       j++;
   }
    *returnSize=j;
    return re;
}
