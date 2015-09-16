/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *r,i,p;
    r=(int *)malloc(sizeof(int)*numsSize);
    r[0]=1;
    p=nums[numsSize-1];
    for(i=1;i<numsSize;i++) r[i]=r[i-1]*nums[i-1];
    for(i=numsSize-2;i>=0;i--){
        r[i]*=p;
        p*=nums[i];
    } 
    *returnSize=numsSize;
    return r;
}
