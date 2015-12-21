typedef struct {
    int value;
    int min;
    struct MinStack *next;

} MinStack;

int leftsize;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->next=NULL;
    leftsize = maxSize;
}

void minStackPush(MinStack *stack, int element) {
    if(leftsize==0) return;
    MinStack *temp1=NULL,*temp2=NULL;
    temp1=stack->next;
    temp2=(MinStack *)malloc(sizeof(MinStack));
    temp2->value = element;
    temp2->next = temp1;
    stack->next=temp2;
    if(temp1==NULL || element < temp1->min){
        temp2->min = element;
    }else{
        temp2->min = temp1->min;
    }
    leftsize--;

}

void minStackPop(MinStack *stack) {
    MinStack *temp1=NULL;
    temp1 = stack->next;
    if(temp1!=NULL){
        stack->next = temp1->next;
        leftsize++;
        free(temp1);
    }
}

int minStackTop(MinStack *stack) {
    MinStack *temp1=NULL;
    temp1 = stack->next;
    if(temp1!=NULL){
        return temp1->value;
    }
}

int minStackGetMin(MinStack *stack) {
    MinStack *temp1=NULL;
    temp1 = stack->next;
    if(temp1!=NULL){
        return temp1->min;
    }
}

void minStackDestroy(MinStack *stack) {
    MinStack *temp1=NULL,*temp2=NULL;
    temp1 = stack ->next;
    stack->next = NULL;
    while(temp1!=NULL){
        temp2=temp1->next;
        free(temp1);
        temp1=temp2;
    }
}
