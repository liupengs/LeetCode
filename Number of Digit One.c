int countDigitOne(int n) {
   long long a[32][2],t=0,t1,i=0,sum=0;
   if(n<0) return 0;
   t1=10;
   while(t1<=n){
       t=t1/10+10*t;
       a[i][0]=t;
       a[i][1]=t1;
       t1*=10;
       i++;

   }
   i-=1;
   while(n>9){
       t=n/a[i][1];
       if(t==0){
           i--;
           continue;
       }else{
           if(t==1){
               sum+=(a[i][0]+n-a[i][1]+1);
           }else{
               sum+=(a[i][0]*t+a[i][1]);
           }
            n-=(t*a[i][1]);
           i--;
       }
   }
   if(n>0) sum++;
   return sum;
}
