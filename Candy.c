int candy(int* ratings, int ratingsSize) {
    int i,now,p,sum;
    if(ratingsSize<1) return 0;
    now=1;
    sum=1;
    p=0;
    for(i=1;i<ratingsSize;i++){
        if(ratings[i]>ratings[i-1]){
            now++;
            p=i;
            sum+=now;        
        }else if(ratings[i]<ratings[i-1]){
            if(now>0) now--;
            if(now<1){
                sum+=(i-p+1);
            }else{
                sum+=now;
            }
        }else if(ratings[i]==ratings[i-1]){
                if(now>1) sum-=(i-p-1)*(now-1);
                sum+=1;
                now=1;
                p=i;
        }
        if(i>0 && i<ratingsSize-1){
            if(ratings[i]<ratings[i-1] && ratings[i+1]>ratings[i]){
                if(now>1) sum-=(i-p)*(now-1);
                now=1;
            }else if(ratings[i]==ratings[i-1] && ratings[i+1]==ratings[i]){
                
            }
        }
    }
    if(i>2 && ratings[i-1]<ratings[i-2] && now>1){
        sum-=(i-1-p)*(now-1);
    }
    return sum;
}
