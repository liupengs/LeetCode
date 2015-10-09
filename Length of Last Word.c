int lengthOfLastWord(char* s) {
    int lens,i,sum=0;
    lens=strlen(s);
    i=lens-1;
    sum=0;
    while(i>=0){
        if(s[i]!=' ') break;
        i--;
    }
    for(i;i>=0 && s[i]!=' ';i--){
        sum++;
    }
    return sum;
}
