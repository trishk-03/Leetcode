class MyCircularQueue {
public:
        int front =0;
        int rear =0;
        int capacity =0;
        int size =0;
        int* q;
    MyCircularQueue(int k) {
        size = 0;
        q = new int[k];
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(size == capacity) return false;
        rear = (front+size)% capacity;
        q[rear]= value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        q[front]= -1;
        front = (front + 1)% capacity;
        size--;
        return true;
    }
    
    int Front() {
        if(size == 0) return -1;
        return q[front];
        
    }
    
    int Rear() {
        if(size == 0) return -1;
        return q[(front + size - 1) % capacity];        
    }
    
    bool isEmpty() {
        if(size == 0 ) return true;
        return false;
    }
    
    bool isFull() {
        if(size == capacity) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */