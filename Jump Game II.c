int jump(int* nums, int numsSize) {
    int e=0,s=0,t,sum=0,i=0;
    numsSize-=1;
    while(e<numsSize){
        sum++;
        t=e;
        for(;i<=t && e<numsSize;i++){
            if(i+nums[i]>e) e=i+nums[i];
        }
    }
    return sum;
}
