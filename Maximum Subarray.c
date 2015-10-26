int maxSubArray(int* nums, int numsSize) {
    int e,sum,max;
    max=sum=nums[0];
    for(e=1;e<numsSize;e++){
        if(sum<0) sum=nums[e];
        else sum+=nums[e];
        max=max>sum?max:sum;
    }
    return max;
}
