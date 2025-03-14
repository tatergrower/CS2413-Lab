typedef struct {
    int data;
} qnode;

typedef struct {
    qnode* arr[101];
    int front;
    int rear;
} MyStack;
//enqueue stack with given value
void nq(MyStack* obj, qnode* val) {
    obj->arr[++obj->rear] = val;
    if (obj->front == -1){
        obj->front = 0;//for index purposes
    }
}

qnode* dq(MyStack* obj) {
    qnode* val = obj->arr[obj->front];
    if(obj->front==obj->rear) {
        obj->front = obj->rear = 0;
    }
    else{
        obj->front++;
    }
    return val;
}
//creates empty stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->front = -1;
    stack->rear = -1;
    return stack;
}
//adds data to node at front, then dqs front, adding to rear
void myStackPush(MyStack* obj, int x) {
    qnode* node = (qnode*)malloc(sizeof(qnode));
    node->data = x;
    nq(obj, node);
    int size = obj->rear - obj->front + 1;
    while (size > 1) {
        qnode* front = dq(obj);
        nq(obj, front);
        size--;
    }
}
//return front val
int myStackPop(MyStack* obj) {
    qnode* front = dq(obj);
    int val = front->data;
    free(front);
    return val;
}

int myStackTop(MyStack* obj) {
    qnode* front = obj->arr[obj->front];
    return front->data;
}

bool myStackEmpty(MyStack* obj) {
    return obj->front == -1;
}

void myStackFree(MyStack* obj) {
    while(!myStackEmpty(obj)){
        qnode* front = dq(obj);
        free(front);
    }
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
