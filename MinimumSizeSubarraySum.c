int minSubArrayLen(int s, int* nums, int numsSize) {
    int start=0,i,len=0,sum=0,minlen=9999999;
    for(i=0;i<numsSize;i++){
        sum+=nums[i];
        len++;
        if(sum>=s){
            minlen=len<minlen?len:minlen;
            while(start<=i){
                sum-=nums[start];
                start++;
                len--;
                if(sum>=s){
                    minlen=len<minlen?len:minlen;
                }else{
                    break;
                }
            }
        }
    }
    return minlen==9999999?0:minlen;
}
