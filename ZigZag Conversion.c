 char* convert(char* s, int numRows) {
    int lens,t=0,m,mark=1,i,j;
    char *r;
    if(numRows<=1) return s;
    lens=strlen(s);
    r=(char *)malloc(sizeof(char)*(lens+1));
    for(i=1;i<=numRows;i++){
        m=1;
        for(j=1;j<=lens;j++){
            if(m==i){
                r[t]=s[j-1];
                t++;
            }
            if(mark==1) {
                if(m==numRows){
                    m--;
                    mark=0;
                }else{
                    m++;
                }
            }else{
                if(m==1){
                    m++;
                    mark=1;
                }else{
                    m--;
                }
            }
        }
    }
    r[lens]='\0';
    return r;
}
