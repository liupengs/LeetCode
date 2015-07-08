int movestart(int *nums,int s,int e,int len){
    int i;
    for(i=s+1;i<e;i++){
        if(nums[i]==nums[s]) return i;
    }
    if(e+1<len) return e+1;
    else return s;
}
int majorityElement(int* nums, int numsSize) {
    int i=1,j=0;
    while(i<numsSize){
        if(nums[i]!=nums[j]){
            j=movestart(nums,j,i,numsSize);
            if(j>i) i++;
        }
        i++;
    }
    return nums[j];
    
}
