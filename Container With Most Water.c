int min(int x,int y){
    return x<y?x:y;
}
int maxArea(int* height, int heightSize) {
    int s,e,max=0,t;
    s=0;e=heightSize-1;
    while(s<e){
        t=min(height[s],height[e])*(e-s);
        max=max<t?t:max;
        if(height[s]<height[e]) s++;
        else e--;
    }
    return max;
}
