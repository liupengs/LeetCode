char* intToRoman(int num) {
    char a[]="IVXLCDM",*r,c;
    int t=0,s,j=0,i;
    r=(char *)malloc(sizeof(char)*20);
    while(num>0){
        s=num%10;
        if(s<4){
            while(s>0){
                r[j++]=a[t];
                s--;
            }
        }else if(s==4){
            r[j++]=a[t+1];
            r[j++]=a[t];
        }else if(s==5){
            r[j++]=a[t+1];
        }else if(s>5 && s<9){
            while(s>5){
                r[j++]=a[t];
                s--;
            }
            r[j++]=a[t+1];
        }else{
            r[j++]=a[t+2];
            r[j++]=a[t];
        }
        t+=2;
        num/=10;
    }
    r[j]='\0';
    s=j/2;
    for(i=0;i<s;i++){
        c=r[i];
        r[i]=r[j-1-i];
        r[j-1-i]=c;
    }
    return r;
}
