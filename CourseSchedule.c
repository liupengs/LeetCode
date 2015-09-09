struct nodes{
    int into;
    int childnum;
    int *child;
};
int canFinish(int numCourses, int **prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
    struct nodes node[numCourses];
    int i,j,t,mark=1;
    if(numCourses==1) return true;
    for(i=0;i<numCourses;i++) {
        node[i].into=0;
        node[i].child=NULL;
        node[i].childnum=0;
    }
    for(i=0;i<prerequisitesRowSize;i++){
        for(j=0;j<prerequisitesColSize-1;j++){
            t=prerequisites[i][j+1];
            node[prerequisites[i][j]].into++;
            node[t].childnum++;
            node[t].child=(int *)realloc(node[t].child,node[t].childnum*sizeof(int));
            node[t].child[node[t].childnum-1]=prerequisites[i][j];
        }
    }
    while(mark){
        mark=0;
        for(i=0;i<numCourses;i++){
            if(node[i].into==0){
                for(j=0;j<node[i].childnum;j++){
                    node[node[i].child[j]].into--;
                }
                node[i].into=-1;
                mark=1;
            }
        }
    }
    for(i=0;i<numCourses;i++){
        if(node[i].into>0) return false;
    }
    return true;
}
