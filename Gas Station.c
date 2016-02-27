int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int i,s=0,all=0,now;
    while(s<gasSize){
        for(i=0;i<gasSize;i++){
           now=(s+i)%gasSize;
           all+=(gas[now]-cost[now]);
           if(all<0){
               all=0;
               s+=(i+1);
               break;
           }
        }
        if(i==gasSize) return s;
    }
    return -1;
}
