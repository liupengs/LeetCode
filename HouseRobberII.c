int getmax(int* nums,int start,int numsSize){
    int a[numsSize],i,f,s,t;
    if(numsSize<1) return 0;
    else if(numsSize==1) return nums[start];
    else if(numsSize==2) return nums[start]>nums[start+1]?nums[start]:nums[start+1];
    else {f=nums[start];s=nums[start+1]>nums[start]?nums[start+1]:nums[start];}
    for(i=2;i<numsSize;i++){
        t=f+nums[start+i]>s?f+nums[start+i]:s;
        f=s;
        s=t;
    }
    return s;
}
int rob(int* nums, int numsSize) {
    int s,f;
    if(numsSize<1) return 0;
    else if(numsSize==1) return nums[0];
    else if(numsSize==2) return nums[0]>nums[1]?nums[0]:nums[1];
    s=getmax(nums,2,numsSize-3)+nums[0];
    f=getmax(nums,1,numsSize-1);
    return s>f?s:f;
}
