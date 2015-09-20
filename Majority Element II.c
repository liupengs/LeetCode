/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void find(int *nums,int numsSize, int *t1, int *t2 ,int *t3){
    int i,j,k,temp;
    i=*t1;
    j=*t2;
    k=*t3;
    while(i<numsSize && j<numsSize && k<numsSize){
        temp=nums[i];
        for(i=i+1;i<numsSize;i++){
            if(nums[i]==temp) break;
            else if(i>j && j<k && nums[i]==nums[j]) break;
            else if(i>k) break;
        }
        if(i==numsSize){j=k=numsSize; break;}
        temp=nums[j];
        for(j=j+1;j<numsSize;j++){
            if(j<k && nums[j]!=nums[i] &&  nums[j]==temp ) break;
            else if(j>k && nums[j]!=nums[i]) break;
        }
        if(j==numsSize) {k=numsSize; break;}
        for(k=k+1;k<numsSize;k++){
            if(nums[k]!=nums[i] && nums[k]!=nums[j] ) break;
        }
        if(k==numsSize) break;
    }
    *t1=i;
    *t2=j;
    *t3=k;
}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int t1,t2=-1,t3=-1,i,one=0,two=0,three=0,*r,use;
    if(numsSize<1) return NULL;
    t1=0;
    for(t2=1;t2<numsSize;t2++)  if(nums[t2]!=nums[t1]) break;
    for(t3=t2+1;t3<numsSize;t3++) if(nums[t3]!=nums[t1] && nums[t3]!=nums[t2]) break;
    find(nums,numsSize,&t1,&t2,&t3);
    one=two=three=0;
    for(i=0;i<numsSize;i++){
        if(t1<numsSize && nums[i]==nums[t1]) one++;
        if(t2<numsSize && nums[i]==nums[t2]) two++;
        if(t3<numsSize && nums[i]==nums[t3]) three++;
    }
    i=numsSize/3;
    use=0;
    r=NULL;
    if(one>i){
        use++;
        r=(int *)realloc(r,sizeof(int)*use);
        r[use-1]=nums[t1];
    }
    if(two>i){
        use++;
        r=(int *)realloc(r,sizeof(int)*use);
        r[use-1]=nums[t2];
    }
    if(three>i){
       use++;
        r=(int *)realloc(r,sizeof(int)*use);
        r[use-1]=nums[t3];
    }
    *returnSize=use;
    return r;

}
