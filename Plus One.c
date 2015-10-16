/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int c,i,*re;
    c=0;
    if(digitsSize<=0) return NULL;
    else digits[digitsSize-1]++;
    for(i=digitsSize-1;i>=0;i--){
        digits[i]=c+digits[i];
        c=digits[i]/10;
        digits[i]%=10;
    }
    if(c>0){
        *returnSize=digitsSize+1;
        re=(int *)malloc(sizeof(int)*(digitsSize+1));
        for(i=digitsSize-1;i>=0;i--){
            re[i+1]=digits[i];
        }
        re[0]=c;
        return re;
    }else{
        re=(int *)malloc(sizeof(int)*(digitsSize));
        for(i=digitsSize-1;i>=0;i--){
            re[i]=digits[i];
        }
        *returnSize=digitsSize;
        return re;
    }
}
