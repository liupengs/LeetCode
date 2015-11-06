#define min(a,b) (a)<(b)?(a):(b)
double findk(int *num1, int *num2, int size1,int size2, int k){
    int t1,t2;
    if(size1==0) return num2[k-1];
    else if(size2==0) return num1[k-1];
    if(k==1) return min(num2[0],num1[0]);
    if(size1<size2) return findk(num2,num1,size2,size1,k);
    t2=min(size2,k/2);
    t1=k-t2;
    if(num1[t1-1]<num2[t2-1]) return findk(num1+t1,num2,size1-t1,size2,k-t1);
    else if(num1[t1-1]>num2[t2-1]) return findk(num1,num2+t2,size1,size2-t2,k-t2);
    else return num1[t1-1];
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len;
    len=nums1Size+nums2Size;
    if(len%2==0){
        return (findk(nums1,nums2,nums1Size,nums2Size,len/2)+findk(nums1,nums2,nums1Size,nums2Size,len/2+1))/2;
    }
    else return findk(nums1,nums2,nums1Size,nums2Size,len/2+1);
}
