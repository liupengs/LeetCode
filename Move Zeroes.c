void moveZeroes(int* nums, int numsSize) {
    int s,e;
    s=0;
    e=0;
    while(s<numsSize){
        while(e<numsSize){
            if(nums[e]==0) break;
            e++;
        }
        while(s<numsSize){
            if(nums[s]!=0 && e<s){
                nums[e]=nums[s];
                nums[s]=0;
                break;
            }
            s++;
        }
        
    }
}
