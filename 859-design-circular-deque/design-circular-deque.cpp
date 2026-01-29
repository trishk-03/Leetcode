class MyCircularDeque {
private:
    int *q;
    int size= 0, capacity =0;
    int front=-1, rear = -1;
public:
    MyCircularDeque(int k) {
        capacity = k;
        q = new int[capacity];
    }
    
bool insertFront(int value) {
    if (size == capacity)
        return false;

    if (front == -1) {  // deque empty
        front = rear = 0;
    } else {
        front = (front - 1 + capacity) % capacity;
    }

    q[front] = value;
    size++;
    return true;
}

    bool insertLast(int value) {
    if(size == capacity)
    return false;
    if(rear == -1){
        front = rear = 0;
    }  
    else{
        rear = (rear +1)% capacity;
    }
     q[rear] = value;
     size++;
     return true;  
    }
    
    bool deleteFront() {
        if(size == 0) return false;
        if( size == 1){
            front = rear = -1;
        }
        else{
            front = (front + 1)% capacity;
        }
        size--;

        return true;
    }
    
    bool deleteLast() {
        if(size == 0) return false;
        if(size == 1){
           front = rear =-1;
        }
        else{
            rear = (rear -1 + capacity)% capacity;
        }
        size--;
        return true;
    }
    
    int getFront() {
       if(front != -1) return q[front];
       return -1; 
    }
    
    int getRear() {
        if(rear != -1) return q[rear];
        return -1;
    }
    
    bool isEmpty() {
       if(size == 0) return true;
       return false; 
    }
    
    bool isFull() {
        if(size == capacity) return true;
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