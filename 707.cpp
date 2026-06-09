class MyLinkedList {
public:

    struct ptr{
        int val;
        ptr* next;
        ptr(int v, ptr* n){
            val = v;
            next = n;
        }
    };

    ptr* start;
    int size = 0;

    MyLinkedList() {
        start = nullptr;
    }
    
    int get(int index) {
        if(index < 0 || index >= size)return -1;
        int idx = 0;
        ptr* tmp = start;
        while(idx!=index){
            tmp = tmp->next;
            idx++;
        }
        return tmp->val;
    }
    
    void addAtHead(int val) {
        ptr* addable = new ptr(val, start);
        start = addable;
        size++;
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)return;
        if(index == 0){
            ptr* tmp = new ptr(val, nullptr);
            if(start){
                tmp->next = start;
                start = tmp;
            } else {
                start = tmp;
            }
            size++;
            return;
        }
        int idx = 0;
        ptr* prev = nullptr;
        ptr* tmp = start;
        while(idx!=index){
            prev = tmp;
            tmp = tmp->next;
            idx++;
        }
        ptr* addable = new ptr(val, tmp);
        if(prev)prev->next = addable;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index == 0){
            if(!start)return;
            start = start->next;
            size--;
            return;
        }
        if(index < 0 || index >= size)return;
        int idx = 0;
        ptr* prev = nullptr;
        ptr* tmp = start;
        while(idx!=index){
            prev = tmp;
            tmp = tmp->next;
            idx++;
        }

        if(prev){
            prev->next = tmp->next;
            delete(tmp);
        } else {
            start = tmp->next;
            delete(tmp);
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
