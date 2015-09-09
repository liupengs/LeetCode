int addDigits(int num) {
    int t;
    if(num<10) return num;
    while(num>=10){
        t=0;
        while(num>0){
            t+=num%10;
            num/=10;
        }
        num=t;
    }
    return t;
}
