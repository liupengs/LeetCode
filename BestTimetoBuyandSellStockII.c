int maxProfit(int* prices, int pricesSize) {
    int s,i,sum=0;
    if(pricesSize<2) return 0;
    for(i=1,s=prices[0];i<pricesSize;i++){
        if(prices[i]>s) sum+=(prices[i]-s);
        s=prices[i];
    }
    return sum;
}
