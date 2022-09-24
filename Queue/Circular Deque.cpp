class MyCircularDeque {
    
    int *arr;
    int front;
    int rear;
    int size;
public:
    
    MyCircularDeque(int k) {
        size = k;
        front=-1;
        rear = -1;
        arr = new int[size];
    }
    
    bool insertFront(int value) {
        if((front==0 && rear == size-1)||(rear == (front-1)%(size-1))){
            return false;
        }
        else if(front==-1 && rear==-1) {
            front=rear=0;
        }
        else if(rear!=size-1 && front==0) {
            front=size-1;
        }
        else{
            front--;
        }
        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if((front==0 && rear == size-1)||(rear == (front-1)%(size-1))) {
            return false;
        }
        else if(rear==-1 && front==-1) {
            rear=front=0;
        }
        else if(front!=0 && rear==size-1) {
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(front==-1 && rear==-1) {
            return false;
        }
        arr[front] =  -1;
        if(front==rear) {
            front=rear=-1;
        }
        else if(front == size-1 ) {
            front=0;
        }
        else{
            front++;
        }
        return true;
    }
    
    bool deleteLast() {
        if(front==-1) {
            return false;
        }
        arr[front] = -1;
        if(front==rear) {
            front=rear=-1;
        }
        else if(rear==0 ) {
            rear = size-1;
        }
        else{
            rear--;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((front==0 && rear == size-1)||(front!=0 && rear == (front-1)%(size-1))){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */