/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct list{
    int value;
    int index;
}list;

int cmp(const void *a, const void *b)
{
     struct list *aa=(list *)a;
     struct list *bb=(list *)b;
     return aa->value - bb->value;
}

int* twoSum(int* nums, int numsSize, int target) {
    int start=0,end=numsSize-1,*a,sum,i;
    list *l;
    l=(list *)malloc(numsSize*sizeof(list));
    a=(int *)malloc(2*sizeof(int));
    for(i=0;i<numsSize;i++){
        l[i].index=i;
        l[i].value=nums[i];
    }
    qsort(l,numsSize,sizeof(list),cmp);
    sum=l[start].value +l[end].value;
    while(sum!=target){
        if(sum>target) end--;
        if(sum<target) start++;
        sum=l[start].value +l[end].value;
    }
    a[0]=l[start].index<l[end].index?l[start].index+1:l[end].index+1;
    a[1]=l[start].index<l[end].index?l[end].index+1:l[start].index+1;
    return a;
}
