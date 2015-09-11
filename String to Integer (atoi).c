 int myAtoi(char* str) {
    int i=0,s=0,mark=1,lens,sum=0,t;
    lens=strlen(str);
    if(lens<=0) return 0;

    while(str[i]==' '){
        i++;
    }

    if(str[i]=='-'){
        mark=-1;
        s=i+1;
    }else if(str[i]=='+'){
        mark=1;
        s=i+1;
    }else{
        s=i;
    }
    for(i=s;(i<lens && (str[i]>='0' && str[i]<='9'));i++){
        t=str[i]-'0';
        if(sum>=214748365) {
            if(mark==1) return 2147483647;
            else return -2147483648;
        }
        else if(mark==1 && t>7 && sum>=214748364 ) return 2147483647;
        else if(mark==-1 && t>8 && sum>=214748364 ) return -2147483648;
        sum=sum*10+t;
    }
    return mark*sum;
}
