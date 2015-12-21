/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int *re,i,t=1,j,t1,t2;
    re = (int *)malloc(sizeof(int)*(rowIndex+1));
    re[0] =1;
    while(t<=rowIndex){
        re[t] = 1;
        for(j=t-1;j>0;j--) re[j] = re[j]+re[j-1]; 
        t++;
    }
    *returnSize = rowIndex+1;
    return re;
}
