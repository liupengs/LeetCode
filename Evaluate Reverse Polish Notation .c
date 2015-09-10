int evalRPN(char** tokens, int tokensSize) {
    int i,a[tokensSize],now=0;
    for(i=0;i<tokensSize;i++){
        if(strcmp(tokens[i],"+")==0){
            a[now-2]=a[now-1]+a[now-2];
            now--;
        }else if(strcmp(tokens[i],"-")==0){
            a[now-2]=a[now-2]-a[now-1];
            now--;
        }else if(strcmp(tokens[i],"*")==0){
            a[now-2]=a[now-2]*a[now-1];
            now--;
        }else if(strcmp(tokens[i],"/")==0){
            a[now-2]=a[now-2]/a[now-1];
            now--;
        }else{
            a[now]=atoi(tokens[i]);
            now++;
        }
    }
    return a[0];
}
