/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **r=NULL,now=0;
int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}
void getd(int *nums,int o,int start,int end,int sum){
    int i;
    while(start<end){
        if(nums[start]+nums[end]<sum){
            start++;
        }else if(nums[start]+nums[end]>sum){
            end--;
        }else{
            if(now==0){
                r=(int **)realloc(r,sizeof(int **)*(now+1));
                r[now]=(int *)malloc(sizeof(int)*3);
                r[now][0]=o;
                r[now][1]=nums[start];
                r[now][2]=nums[end];
                now++;
            }else{
                for(i=now-1;i>=0;i--){
                    if(r[i][0]==o && r[i][1]==nums[start] && r[i][2]==nums[end]) break;
                }
                if(i==-1){
                    r=(int **)realloc(r,sizeof(int **)*(now+1));
                    r[now]=(int *)malloc(sizeof(int)*3);
                    r[now][0]=o;
                    r[now][1]=nums[start];
                    r[now][2]=nums[end];
                    now++;
                }
                start++;
                end--;
            }
        }
    }
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i;
    r=NULL;now=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(i=0;i<numsSize-2;i++){
        getd(nums,nums[i],i+1,numsSize-1,0-nums[i]);
    }
    *returnSize=now;
    return r;
}
