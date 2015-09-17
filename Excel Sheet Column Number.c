int titleToNumber(char* s) {
    int i,lens,t,sum=0;
    lens=strlen(s);
    for(i=0;i<lens;i++){
        sum=sum*26+s[i]-'A'+1;
    }
    return sum;
}
