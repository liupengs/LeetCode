int missingNumber(int* nums, int numsSize) {
    int i,min=9999999,max=-9999999,sum=0;
    for(i=0;i<numsSize;i++){
       sum+=nums[i];
       if(min>nums[i]) min=nums[i];
       if(nums[i]>max) max=nums[i];
    }
    sum=(max+min)*(max-min+1)/2-sum;
    if(sum!=0) return sum;
    else{
        if(min!=0) return 0;
        else return max+1;
    }
}
