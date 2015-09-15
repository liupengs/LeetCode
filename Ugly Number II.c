int nthUglyNumber(int n) {
    int u[n],i,s2=1,s3=2,s5=4,t2,t3,t5,min,*t;
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 3;
    else if(n==4) return 4;
    else if(n==5) return 5;
    u[0]=1;u[1]=2;u[2]=3,u[3]=4;u[4]=5;
    for(i=5;i<n;i++){
        min=9999999;
        while(s2<i){
            t2=2*u[s2];
            if(t2>u[i-1]){
                min=t2;
                t=&s2;
                break;
            }
            s2++;
        }
        while(s3<i){
            t3=3*u[s3];
            if(t3>u[i-1]){
                if(t3<min){
                    min=t3;
                    t=&s3;
                }
                break;
            }
            s3++;
        }
        while(s5<i){
            t5=5*u[s5];
            if(t5>u[i-1]){
                if(t5<min){
                    min=t5;
                    t=&s5;
                }
                break;
            }
            s5++;
        }
        (*t)++;
        u[i]=min;
    }
    return u[n-1];
}
