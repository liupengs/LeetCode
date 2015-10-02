void change(int *nums,int s, int e){
    int t;
    for(;s<e;s++,e--){
        t=nums[s];
        nums[s]=nums[e];
        nums[e]=t;
    }
}
void nextPermutation(int* nums, int numsSize) {
    int i,j,t;
    for(i=numsSize-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            for(j=numsSize-1;j>i;j--){
                if(nums[j]>nums[i]) break;
            }
            t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
            change(nums,i+1,numsSize-1);
            return;
        }
    }
    change(nums,0,numsSize-1);
}
