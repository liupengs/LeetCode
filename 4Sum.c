/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **r,now;
int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}
void addnow(int *nums,int one,int two,int three,int four){
    r=(int **)realloc(r,sizeof(int **)*(now+1));
    r[now]=(int *)malloc(sizeof(int)*4);
    r[now][0]=nums[one];
    r[now][1]=nums[two];
    r[now][2]=nums[three];
    r[now][3]=nums[four];
    now++;
}
void getd(int *nums,int o,int s,int end,int sum){
    int i,start;
    start=s+1;
    while(start<end){
        if(nums[start]+nums[end]<sum) {start++;continue;}
        else if(nums[start]+nums[end]>sum) {end--;continue;}
        else if(now==0) addnow(nums,o,s,start,end);
        else{
            for(i=now-1;i>=0;i--){
                if(r[i][0]==nums[o] && r[i][1]==nums[s] && r[i][2]==nums[start] && r[i][3]==nums[end]) break;
            }
            if(i==-1)addnow(nums,o,s,start,end);
        }
        start++;
        end--;
    }
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;
    r=NULL;now=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(i=0;i<numsSize-3;i++)
        for(j=i+1;j<numsSize-2;j++)
            getd(nums,i,j,numsSize-1,target-nums[i]-nums[j]);
    (*returnSize)=now;
    return r;
}
