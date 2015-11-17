int largestRectangleArea(int* height, int heightSize) {
    int p[heightSize][2],i,j,max=0,t,num;
    if(heightSize==0) return 0;
    p[0][0]=height[0];
    p[0][1]=1;
    for(i=1,j=0;i<heightSize;i++){
        if(p[j][0]<height[i]){
            j++;
            p[j][0]=height[i];
            p[j][1]=1;
        }else if(p[j][0]==height[i]){
            p[j][1]++;
        }else{
            num=0;
            while(j>=0 && p[j][0]>height[i]){
                num+=p[j][1];
                t=p[j][0]*num;
                max=max>t?max:t;
                j--;
            }
            if(j==-1){
                j=0;
                p[j][0]=height[i];
                p[j][1]=num+1;
            }else{
                if(p[j][0]==height[i]) p[j][1]+=(num+1);
                else{
                    j++;
                    p[j][0]=height[i];
                    p[j][1]=num+1;
                }
            }
        }
    }
    num=0;
    while(j>=0){
        num+=p[j][1];
        t=p[j][0]*num;
        max=max>t?max:t;
        j--;
    }
    return max;
}
