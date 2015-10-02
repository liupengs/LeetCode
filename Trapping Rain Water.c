int trap(int* height, int heightSize) {
    int max,p,i,j,sum,t;
    max=0;
    sum=0;
    for(i=0;i<heightSize;i++){
        if(height[i]>=max){
            if(max!=0){
                for(j=p+1;j<i;j++){
                    sum+=max-height[j];
                }
            }
            p=i;
            max=height[i];
        }
    }
    max=0;
    for(i=heightSize-1;i>=p;i--){
        if(height[i]>=max){
            if(max!=0){
                for(j=t-1;j>i;j--){
                    sum+=max-height[j];
                }
            }
            t=i;
            max=height[i];
        }
    }
    return sum;
}
