typedef struct {
    int Stack1[100];
    int Stack2[100];
    int Stack1Top;
    int Stack2Top;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->Stack1Top = -1;
    queue->Stack2Top = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    while (obj->Stack2Top != -1) {
        obj->Stack1[++obj->Stack1Top] = obj->Stack2[obj->Stack2Top--];
    }
    obj->Stack1[++obj->Stack1Top] = x;
    while (obj->Stack1Top != -1) {
        obj->Stack2[++obj->Stack2Top] = obj->Stack1[obj->Stack1Top--];{
    }
}

int myQueuePop(MyQueue* obj) {
    return obj->Stack2[obj->Stack2Top--];
}

int myQueuePeek(MyQueue* obj) {
    return obj->Stack2[obj->Stack2Top];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->Stack2Top == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
