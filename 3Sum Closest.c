int min;
int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}
void getd(int *nums,int o,int start,int end,int target){
    int t;
    while(start<end){
        t=o+nums[start]+nums[end];
        if(abs(target-t)<abs(target-min)) min=t;
        if(t>target){
            end--;
        }else if(t<target){
            start++;
        }else{
            min=target;
            return;
        }
    }
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int i;
    min=9999999;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(i=0;i<numsSize-2;i++){
        getd(nums,nums[i],i+1,numsSize-1,target);
        if(min==target) return target;
    }
    return min;
}
