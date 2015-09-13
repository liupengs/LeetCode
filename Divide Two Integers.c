#define MAX_INT 2147483647
int divide(int dividend, int divisor) {

    int j=0;
    long long mark=1,one,two,sum=0,t,temp,a[32][2];
    one=(long long) dividend;
    two=(long long) divisor;

    if(one<0){ mark*=(-1);one=llabs(one);}
    if(two<0){ mark*=(-1);two=llabs(two);}

    j=0;
    temp=two;
    t=1;

    while(one>=temp){
        a[j][0]=temp;
        a[j][1]=t;
        temp+=temp;
        t+=t;
        j++;
    }

    j--;
    while(one>=two && j>=0){
        while(one>=a[j][0]){
            one-=a[j][0];
            sum+=a[j][1];
        }
        j--;
    }
    sum=sum*mark;
    if(sum>MAX_INT) return MAX_INT;
    else return (int) sum;

}
