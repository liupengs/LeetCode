int firstMissingPositive(int* nums, int numsSize) {
    int *mark,i;
    if(numsSize<1) return 1;
    mark=(int *)calloc(numsSize+2,sizeof(int));
    for(i=0;i<numsSize;i++)
        if(nums[i]>0 && nums[i]<numsSize+2) mark[nums[i]]=1;
    for(i=1;i<=numsSize;i++)
        if(mark[i]==0) {
            free(mark);
            return i;
        }
}
