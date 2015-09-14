/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int have(char *input, int start, int end,int *first){
    int i,sum=0;
    for(i=start;i<=end;i++){
        if(input[i]=='+' || input[i]=='-' || input[i]=='*') sum++;
        else if(sum==0){
            (*first)=(*first)*10+input[i]-'0';
        }
    }
    return sum;
}

int *kinds(char *input,int start,int end, int *rsize){
    int *temp=NULL,i,j,k,*temp1,*temp2,a,b,t,all=0,sum,first=0;
    temp=(int *)malloc(sizeof(int));
    sum=have(input,start,end,&first);
    if(sum==0){
        temp[0]=first;
        *rsize=1;
        return temp;
    }
    for(i=start;i<=end;i++){
        if(input[i]=='+' || input[i]=='-' || input[i]=='*'){
            temp1=kinds(input,start,i-1, &a);
            temp2=kinds(input,i+1,end,&b);
            t=a*b;
            temp=(int *)realloc(temp,sizeof(int)*(all+t));
            for(j=0;j<a;j++)
                for(k=0;k<b;k++){
                    if(input[i]=='+'){
                        temp[all]=temp1[j]+temp2[k];
                    }else if(input[i]=='-'){
                        temp[all]=temp1[j]-temp2[k];
                    }else if(input[i]=='*'){
                        temp[all]=temp1[j]*temp2[k];
                    }
                    all++;
                }
        }

    }
    *rsize=all;
    return temp;
}
int* diffWaysToCompute(char* input, int* returnSize) {
    int *r=NULL,a=0;
    r=kinds(input,0,strlen(input)-1,&a);
    * returnSize=a;
    return r;
}
