bool isUgly(int num) {
    if(num==1) return true;
    while(num!=2 && num!=3 && num!=5 && num!=0){
        if(num%2==0) num/=2;
        else if(num%3==0) num/=3;
        else if(num%5==0) num/=5;
        else return false;
    }
    if(num!=0) return true;
    else return false;
}
