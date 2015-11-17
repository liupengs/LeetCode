bool searchRange(int* nums, int s, int e,int target){
    int t;
    if(s>e) return false;
    t=(s+e)/2;
    if(nums[t]==target) return true;
    else if(nums[t]>nums[e]){
        if(nums[t]>target && nums[s]<=target) return searchRange(nums,s,t-1,target);
        else  return searchRange(nums,t+1,e,target);
    }else if(nums[t]<nums[e]){
        if(nums[e]>=target && target>nums[t]) return searchRange(nums,t+1,e,target);
        else  return searchRange(nums,s,t-1,target);
    }else{
        return  (searchRange(nums,s,t-1,target) || searchRange(nums,t+1,e,target));
    }
}
bool search(int* nums, int numsSize, int target) {
    return searchRange(nums,0,numsSize-1,target);
}
