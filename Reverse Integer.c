 int reverse(int x) {
    int sum=0,mark;
    if(x<0){
        mark=-1;
        x*=(-1);
    }else{
        mark=1;
    }
    while(x>0){
        sum=sum*10+x%10;
        x/=10;
        if(x>0 && sum>=214748365) return 0;
        else if(mark==1 && x>7 && sum>=214748364 ) return 0;
        else if(mark==-1 && x>8 && sum>=214748364 ) return 0;
    }
    return mark*sum;
}
