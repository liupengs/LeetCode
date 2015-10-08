int pointat(char *nums,int lens){
    int i;
    for(i=0;i<lens;i++){
        if(nums[i]=='.') return lens-i-1;
    }
    return 0;
}
char* multiply(char* num1, char* num2) {
    int len1,len2,i,point,t,t1,m=0,j,k,n;
    int *temp[10],*sum;
    char *re;
    for(i=0;i<10;i++) temp[i]=NULL;
    len1=strlen(num1);
    len2=strlen(num2);
    if(len1==0 || len2==0) return NULL;
    point=pointat(num1,len1)+pointat(num2,len2);
    sum=(int *)calloc(len1+len2+3,sizeof(int));
    re=(char *)calloc(len1+len2+3,sizeof(char));
    m=0;
    for(i=len2-1;i>=0;i--){
        t=num2[i]-'0';
        if(t>0 && t<=9){
            if(temp[t]==NULL){
                temp[t]=(int *)calloc(len1+2,sizeof(int));
                for(k=0,n=len1-1;n>=0;n--){
                    t1=num1[n]-'0';
                    if(t1>=0 && t1<=9){
                        temp[t][k]+=t1*t;
                        if(temp[t][k]>9){
                            temp[t][k+1]+=temp[t][k]/10;
                            temp[t][k]%=10;
                        }
                        k++;
                    }
                }
                while(temp[t][k]!=0) {
                    k++;
                }
                temp[t][k]=-1;
            }
            for(j=m,k=0;temp[t][k]!=-1;k++,j++){
                sum[j]+=temp[t][k];
                if(sum[j]>9){
                    sum[j+1]+=sum[j]/10;
                    sum[j]%=10;
                }
            }
            m++;
        }else if(t==0){
            m++;
        }
    }
    for(i=len1+len2+2;i>=0;i--){
        if(sum[i]!=0) break;
    }
    n=0;
    if(i+1<=point && i>-1){
        re[n++]='0';
        if(point>i+1) re[n++]='.';
        for(j=i+1,n;j<point;j++,n++){
            re[n]='0';
        }
    }else if(i==-1){
        re[0]='0';
        n=1;
    }
    for(i,j=n;i>=0;i--,j++){
        if(point!=0 && i==point-1){
            re[j]='.';
            j++;
        }
        re[j]=(char) sum[i]+48;
    }
    re[j]='\0';
    return re;
}
