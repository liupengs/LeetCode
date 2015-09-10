int num(int *nums,int start,int end,int numsSize,int k){
    int t,s,e;
    t=nums[start];
    s=start;
    e=end;
    while(s<e){
        while(e>s){
            if(nums[e]<t){
                nums[s]=nums[e];
                s++;
                break;
            }
            e--;
        }
        while(s<e){
            if(nums[s]>t){
                nums[e]=nums[s];
                e--;
                break;
            }
            s++;
        }
        nums[s]=t;
    }
    if(numsSize-s==k) return nums[s];
    else if(numsSize-s<k) return num(nums,start,s-1,numsSize,k);
    else return num(nums,e+1,end,numsSize,k);
}
int findKthLargest(int* nums, int numsSize, int k) {
    return num(nums, 0, numsSize-1, numsSize, k);
}
