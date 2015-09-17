int findPeakElement(int* nums, int numsSize) {
    int i;
    if(numsSize==1) return 0;
    for(i=0;i<numsSize;i++){
        if(i==0 && nums[0]>nums[1]) return 0;
        else if(i==numsSize-1 && nums[i]>nums[i-1]) return i;
        else if(i>0 && i<numsSize-1 && nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;
    }
}
