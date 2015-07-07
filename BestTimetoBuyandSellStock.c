int maxProfit(int* prices, int pricesSize) {
    int i,max=0,now;
    if(pricesSize<2) return 0;
    for(i=1,now=prices[0];i<pricesSize;i++){
        if(prices[i]-now>max) max=prices[i]-now;
        if(prices[i]<now) now=prices[i];
    }
    return max;
}
