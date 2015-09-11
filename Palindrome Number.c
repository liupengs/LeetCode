bool isPalindrome(int x) {
    if(x<0) return false;
    if(x==0) return true;
    int sum=0;
    while(x>0){
        sum=sum*10+x%10;
        if(sum==0) return false;
        if(sum==x || sum==x/10) return true;
        x/=10;
        if(sum>x) return false;
    }
    return false;
}
