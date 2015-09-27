int longestValidParentheses(char* s) {
     int max,left,right,len,i;
     max=left=right=0;
     len=strlen(s);
     for(i=0;i<len;i++){
         if(s[i]=='('){
             left++;
         }else if(s[i]==')'){
             right++;
             if(right==left){
                 max=right>max?right:max;
             }else if(right>left){
                left=right=0;
             }
         }
     }
     left=right=0;
     for(i=len-1;i>=0;i--){
         if(s[i]==')'){
             left++;
         }else if(s[i]=='('){
             right++;
             if(right==left){
                 max=right>max?right:max;
             }else if(right>left){
                left=right=0;
             }
         }
     }
     return max*2;
}
