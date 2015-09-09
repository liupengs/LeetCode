/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct nodes{
    int into;
    int childnum;
    int *child;
};
int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize) {
    struct nodes node[numCourses];
    int i,j,t,mark=1,*r;
    r=(int *)malloc(sizeof(int)*numCourses);
    if(numCourses==1){
        r[0]=0;
        * returnSize=1;
        return r;
    }
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
    t=0;
    while(mark){
        mark=0;
        for(i=0;i<numCourses;i++){
            if(node[i].into==0){
                for(j=0;j<node[i].childnum;j++){
                    node[node[i].child[j]].into--;
                }
                node[i].into=-1;
                mark=1;
                r[t]=i;
                t++;
            }
        }
    }
    for(i=0;i<numCourses;i++){
        if(node[i].into>0) return NULL;
    }
    * returnSize=numCourses;
    return r;
}
