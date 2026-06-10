class MyCircularQueue {
public:

    struct ptr{
        int val;
        ptr* next;
        ptr(int v, ptr* n){
            val = v;
            next = n;
        }
    };
    
    int max;
    int size;
    ptr* start;
    ptr* curr;

    MyCircularQueue(int k) {
        max = k;
        size = 0;
        start = nullptr;
        curr = nullptr;
    }
    
    bool enQueue(int value) {
        if(size == max)return false;
        ptr* addable = new ptr(value, nullptr);
        if(size == 0){
            start = addable;
            curr = addable;
            size++;
            return true;
        }
        curr->next = addable;
        curr = addable;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0)return false;
        if(size == 1){
            delete(start);
            start = curr = nullptr;
            size--;
            return true;
        }
        ptr* temp = start->next;
        delete(start);
        start = temp;
        size--;
        return true;
    }
    
    int Front() {
        if(!start)return -1;
        return start->val;
    }
    
    int Rear() {
        if(!curr)return -1;
        return curr->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == max;
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
