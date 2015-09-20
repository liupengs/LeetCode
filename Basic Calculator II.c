int getnext(char *s,int lens,int *now){
    int i,sum=0,mark=0;
    for(i=(*now);i<lens;i++){
        if(s[i]>='0' && s[i]<='9'){
            sum=sum*10+s[i]-'0';
            mark=1;
        }else if(mark==1){
            break;
        }
    }
    if(mark==0) return -1;
    (*now)=i;
    return sum;
}
int calculate(char* str) {
    int lens,i=0,sum=0,use=0,one;
    char two,*s;
    lens=strlen(str);
    if(lens==0) return 0;
    s=(char *)malloc(sizeof(char)*(lens+1));
    strcpy(s,str);
    s[lens]='+';
    sum=getnext(s,lens,&i);
    while(i<=lens){
         if(sum==-1) break;
         if(s[i]=='+' || s[i]=='-'){
            if(use==0){
                one=sum;
                two=s[i];
                use=2;
            }else{
                if(two=='+') one=one+sum;
                else if(two=='-') one=one-sum;
                two=s[i];
                use=2;
            }
            sum=getnext(s,lens,&i);
        }else if(s[i]=='*' || s[i]=='/'){
            if(s[i]=='*') sum*=getnext(s,lens,&i);
            else sum/=getnext(s,lens,&i);
        }else{
            i++;
        }
    }
    return one;
}
