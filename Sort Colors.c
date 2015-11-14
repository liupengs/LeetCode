void sortColors(int* nums, int numsSize) {
    int s,e,t;
    s=0;
    e=numsSize-1;
    while(s<e){
        while(s<e){
            if(nums[s]==2) break;
            else s++;
        }
        while(s<e){
            if(nums[e]!=2) break;
            else e--;
        }
        if(s<e){
            t=nums[s];
            nums[s]=nums[e];
            nums[e]=t;
        }
    }
    s=0;
    if(e<numsSize-1) e-=1;
    while(s<e){
        while(s<e){
            if(nums[s]==1) break;
            else s++;
        }
        while(s<e){
            if(nums[e]==0) break;
            else e--;
        }
        if(s<e){
            t=nums[s];
            nums[s]=nums[e];
            nums[e]=t;
        }
    }
}
