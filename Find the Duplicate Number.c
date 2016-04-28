int findDuplicate(int* nums, int numsSize) {
    int i,*hash;
    hash=(int *)calloc(numsSize,sizeof(int));
    for(i=0;i<numsSize && hash[nums[i]]==0;i++){
        hash[nums[i]]=1;
    }
    return nums[i];
}
