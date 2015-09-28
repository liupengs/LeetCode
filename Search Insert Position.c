int searchInsert(int* nums, int numsSize, int target) {
    int s,e,t;
    if(numsSize==0) return 0;
    s=0;
    e=numsSize-1;
    while(s<=e){
        if(s==e){
            break;
        }
        t=(s+e)/2;
        if(target<nums[t]){
            e=t-1;
        }else if(target>nums[t]){
            s=t+1;
        }else{
            return t;
        }
    }
    if(nums[s]==target) return s;
    else if(nums[s]>target) return s;
    else return s+1;
    
}
