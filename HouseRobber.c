int rob(int* nums, int numsSize) {
    int a[numsSize],i;
    if(numsSize<1) return 0;
    else if(numsSize==1) return nums[0];
    else if(numsSize==2) return nums[0]>nums[1]?nums[0]:nums[1];
    else nums[1]=nums[1]>nums[0]?nums[1]:nums[0];
    for(i=2;i<numsSize;i++){
        nums[i]=nums[i-2]+nums[i]>nums[i-1]?nums[i-2]+nums[i]:nums[i-1];
    }
    return nums[i-1];
}
