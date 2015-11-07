int max;
void great(int *nums,int numsSize,int *p,int s){
    if(p[s]!=0) return;
    else p[s]=1;
    int i=s+1;
    while(i<numsSize){
        if(nums[i]>nums[s]){
            if(p[i]==0) great(nums,numsSize,p,i);
            p[s]=p[s]>(1+p[i])?p[s]:(1+p[i]);
        }
        i++;
    }
    max=max>p[s]?max:p[s];
}
int lengthOfLIS(int* nums, int numsSize) {
    int p[numsSize],i;
    memset(p,0,sizeof(p));
    max=0;
    for(i=0;i<numsSize;i++) great(nums,numsSize,p,i);
    return max;
}
