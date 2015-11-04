typedef struct {
    int *first;
    int *second;
    int lenf;
    int lens;
    int max;
} Queue;
/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    queue->first=(int *)malloc(sizeof(int)*maxSize);
    queue->second=(int *)malloc(sizeof(int)*maxSize);
    queue->lenf=0;
    queue->lens=0;
    queue->max=maxSize;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    if(queue->lenf+queue->lens==queue->max) return;
    queue->first[queue->lenf]=element;
    queue->lenf++;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    int i;
    if(queue->lens==0){
        for(i=queue->lenf-1;i>=0;i--){
            queue->second[queue->lens]=queue->first[i];
            queue->lens++;
        }
        queue->lenf=0;
    }
    if(queue->lens>0) queue->lens--;
}

/* Get the front element */
int queuePeek(Queue *queue) {
    int i;
    if(queue->lens==0){
        for(i=queue->lenf-1;i>=0;i--){
            queue->second[queue->lens]=queue->first[i];
            queue->lens++;
        }
        queue->lenf=0;
    }
    if(queue->lens>0) return queue->second[queue->lens-1];

}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    if(queue->lenf==0 && queue->lens==0) return true;
    else return false;
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    free(queue->first);
    free(queue->second);
    queue->lenf=0;
    queue->lens=0;
    queue->max=0;
    //free(queue);
}
