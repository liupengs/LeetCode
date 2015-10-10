bool canJump(int* nums, int numsSize) {
    int e,i;
    e=0;
    for(i=0;i<numsSize;i++){
        if(i>e) return false;
        else if(i+nums[i]>e) e=i+nums[i];
    }
    return true;
}
