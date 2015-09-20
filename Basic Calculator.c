int cal(char *s, int start, int *end,int lens)
{
    int i,c=1,t=0,one,use=0,sum=0;
    char two;
    i=start;
    while(c>0 && i<lens){
        if(s[i]>='0' && s[i]<='9') sum=sum*10+s[i]-'0';
        else if(s[i]=='('){
            t=cal(s,i+1,&i,lens);
            sum=t;
            continue;
        }else if(s[i]=='+' || s[i]=='-'){

            if(use==0){
                one=sum;
                two=s[i];
                use=2;
            }else{
                if(two=='+') one+=sum;
                else one-=sum;
            }
            two=s[i];
            sum=0;
        }else if(s[i]==')'){
            *end=i+1;
            c--;
            if(use==2) sum=two=='-'?(one-sum):(one+sum);
            return sum;
        }
        i++;
    }
    if(use==2) sum=two=='-'?(one-sum):(one+sum);
    else return sum;
}
int calculate(char* s) {
    int lens,i=0;
    lens=strlen(s);
    if(lens==0) return 0;
    return cal(s,0,&i,lens);
}
