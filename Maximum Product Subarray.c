int maxProduct(int* nums, int numsSize) {
    int s,e,max,sum;
    if(numsSize<1) return 0;
    for(e=1,s=0,max=nums[0],sum=max;e<numsSize;e++){
        if(nums[e]==0){
            if(sum<0){
                for(;s<e-1 && sum<0;s++){
                    sum/=nums[s];
                    if(sum>max) max=sum;
                }
            }
            sum=0;
            if(sum>max) max=sum;
            s=e+1;
        }else{
            if(sum==0) {
                sum=nums[e];
                s=e;
            }else{
                sum*=nums[e];
            }
            if(sum>max) max=sum;
        }
    }
    for(numsSize-=1;sum<0 && s<numsSize && nums[s]!=0;s++){
        sum/=nums[s];
        if(sum>max) max=sum;
    }
    return max;
}
