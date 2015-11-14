int romanToInt(char* s) {
    char c;
    int sum=0,t,sumlast=0,last=0;
    while((c=*s++)!=0){
        switch(c){
            case 'M':
                t=1000;
                break;
            case 'D':
                t=500;
                break;
            case 'C':
                t=100;
                break;
            case 'L':
                t=50;
                break;
            case 'X':
                t=10;
                break;
            case 'V':
                t=5;
                break;
            case 'I':
                t=1;
                break;
            default:
                return 0;
        }
        if(last!=0){
            if(last<t){
                sum+=(t-sumlast);
                sumlast=last=0;
            }else if(last==t){
                sumlast+=t;
            }else{
               sum+=sumlast;
               sumlast=t;
               last=t;
            }
        }else{
            sumlast=t;
            last=t;
        }
    }
    if(sumlast!=0) sum+=sumlast;
    return sum;
    
}
