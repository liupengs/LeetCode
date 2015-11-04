void rotate(int* nums, int numsSize, int k) {
    int s,e,t;
    k%=numsSize;
    for(s=0,e=numsSize-1;s<e;s++,e--){
        t=nums[s];
        nums[s]=nums[e];
        nums[e]=t;
    }
    for(s=0,e=k-1;s<e;s++,e--){
        t=nums[s];
        nums[s]=nums[e];
        nums[e]=t;
    }
    for(s=k,e=numsSize-1;s<e;s++,e--){
        t=nums[s];
        nums[s]=nums[e];
        nums[e]=t;
    }
}
