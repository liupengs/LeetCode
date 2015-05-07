#include <stdio.h>
#include <stdlib.h>
#define LEN 1
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize==0) return 0;
    int len=0,num=1,i;
    for(i=1;i<numsSize;i++){
        (nums[i]==nums[len])?(num++):(num=1);
        if(num<3){
            len++;
            nums[len]=nums[i];
        }
    }
    return len+1;

}
int main()
{
    int nums[LEN]={1},len,i;
    len=removeDuplicates(nums,LEN);
    printf("len %d\n",len);
    for(i=0;i<len;i++) printf("%d ",nums[i]);
    printf("\n");
    return 0;
}
