/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int i,s,t,*re,bin;
    *returnSize=2;
    re=(int *)calloc(2,sizeof(int));
    for(i=0,s=0;i<numsSize;i++) s^=nums[i];
    t=1;
    while((s&t)==0){
        t<<=1;
    }
    for(i=0;i<numsSize;i++){
        if((t&nums[i])==0){
            re[0]^=nums[i];
        }else{
             re[1]^=nums[i];
        }
    }
    return re;
}
