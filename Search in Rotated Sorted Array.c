int find(int *nums,int s,int e,int target){
    int t;
    if(s>e) return -1;
    if(nums[s]==target){
        return s;
    }else if(nums[e]==target){
        return e;
    }else if(s==e){
        return -1;
    }
    t=(s+e)/2;
    if(nums[s]<=nums[t] && nums[s]<=target && target<=nums[t]){
        return find(nums,s,t,target);
    }else if(nums[s]<=nums[t] && (target>nums[t] || target<=nums[e])){
        return find(nums,t+1,e,target);
    }else if(nums[s]>nums[t] && (target>=nums[s] || target<=nums[t])){
        return find(nums,s,t,target);
    }else if(nums[s]>nums[t] && (target>nums[t] || target<=nums[e])){
        return find(nums,t+1,e,target);
    }else{
        return -1;
    }

}
int search(int* nums, int numsSize, int target) {
    return find(nums,0,numsSize-1,target);
}
