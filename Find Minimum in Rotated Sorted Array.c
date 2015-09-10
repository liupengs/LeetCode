int findMin(int* nums, int numsSize) {
    int min=99999999;
    for(numsSize-=1;numsSize>=0;numsSize--) min=min<nums[numsSize]?min:nums[numsSize];
    return min;
}
