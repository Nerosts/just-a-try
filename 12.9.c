#define _CRT_SECURE_NO_WARNINGS 1


typedef struct {

    int* a;

    int front;

    int back;

    int k;

} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);

bool myCircularQueueIsFull(MyCircularQueue* obj);



MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

    mq->a = (int*)malloc(sizeof(int) * (k + 1));

    mq->front = mq->back = 0;

    mq->k = k;

    return mq;

}



bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if (myCircularQueueIsFull(obj))

    {

        return false;

    }

    obj->a[obj->back] = value;

    obj->back++;

    obj->back %= obj->k + 1;

    return true;

}



bool myCircularQueueDeQueue(MyCircularQueue* obj) {

    if (myCircularQueueIsEmpty(obj))

    {

        return false;

    }

    obj->front++;

    obj->front %= obj->k + 1;

    return true;

}



int myCircularQueueFront(MyCircularQueue* obj) {

    if (myCircularQueueIsEmpty(obj))

    {

        return -1;

    }

    return (obj->a)[obj->front];

}



int myCircularQueueRear(MyCircularQueue* obj) {

    if (myCircularQueueIsEmpty(obj))

    {

        return -1;

    }

    return (obj->a)[(obj->back - 1 + obj->k + 1) % (obj->k + 1)];

}



bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    return obj->front == obj->back;

}



bool myCircularQueueIsFull(MyCircularQueue* obj) {

    return obj->front == (obj->back + 1) % (obj->k + 1);

}



void myCircularQueueFree(MyCircularQueue* obj) {

    free(obj->a);

    obj->a = NULL;

    free(obj);

    obj = NULL;

}



/**

 * Your MyCircularQueue struct will be instantiated and called as such:

 * MyCircularQueue* obj = myCircularQueueCreate(k);

 * bool param_1 = myCircularQueueEnQueue(obj, value);



 * bool param_2 = myCircularQueueDeQueue(obj);



 * int param_3 = myCircularQueueFront(obj);



 * int param_4 = myCircularQueueRear(obj);



 * bool param_5 = myCircularQueueIsEmpty(obj);



 * bool param_6 = myCircularQueueIsFull(obj);



 * myCircularQueueFree(obj);

*/