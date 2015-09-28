/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findstart(int* nums,int s,int e,int target){
    int t;
    if(s>e) return -1;
    while(s<=e){
        printf("star s=%d e=%d\n",s,e);
        if(s==e && nums[s]==target) return s;
        else if(s==e && nums[s]!=target) return -1;
        t=(s+e)/2;
        if(target>nums[t]){
            s=t+1;
        }else{
            e=t;
        }
    }
    return -1;
}
int findend(int* nums,int s,int e,int target){
    int t;
    if(s>e) return -1;
    while(s<=e){
        if(s+1==e){
             if(nums[e]==target) return e;
             else if(nums[s]==target) return s;
             else return -1;
        }else if(s==e && nums[s]==target) return e;
        else if(s==e && nums[s]!=target) return -1;
        t=(s+e)/2;
        if(target<nums[t]){
            e=t-1;
        }else{
            s=t;
        }
    }
    return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *a;
    a=(int *)malloc(sizeof(int)*2);
    * returnSize=2;
    a[0]=findstart(nums,0,numsSize-1,target);
    a[1]=findend(nums,0,numsSize-1,target);
    return a;
}
