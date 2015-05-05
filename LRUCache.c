
typedef struct list{
    int key;
    int value;
    int recentuse;
}list;

list *lists;
int gcapacity,recent=1;

void lruCacheInit(int capacity) {
    int i;
    lists=(list *)malloc((capacity)*sizeof(list));
    gcapacity=capacity;
    for(i=0;i<capacity;i++){
        lists[i].key=-10900;
        lists[i].value=-1;
        lists[i].recentuse=-1;
    }
}

void lruCacheFree() {
    free(lists);
}

int lruCacheGet(int key) {
    int i;
    for(i=0;i<gcapacity;i++){
        if(lists[i].key==key){
            lists[i].recentuse=recent;
            recent++;
            return lists[i].value;
        }
    }
    return -1;
}

void lruCacheSet(int key, int value) {
    int i,minr=lists[0].recentuse,min=0;
    for(i=0;i<gcapacity;i++){
        if(lists[i].key==key){
            lists[i].value=value;
            lists[i].recentuse=recent;
            recent++;
            return;
        }
        if(lists[i].recentuse<minr){
            min=i;
            minr=lists[i].recentuse;
        }
    }
    lists[min].key=key;
    lists[min].value=value;
    lists[min].recentuse=recent;
    recent++;
}
