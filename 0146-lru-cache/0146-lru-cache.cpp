class LRUCache {
public:
    struct Node{
        int val;
        int key;
        Node* next;
        Node* prev;
    };

    unordered_map<int, Node*> map;
    int size = 0;
    int loglen = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    LRUCache(int capacity) {
        size = capacity;
        head = new Node();
        tail = new Node();
        head->prev = tail->next = nullptr;
        head->next = tail; tail->prev = head;
    }
    
    int get(int key) {
        if(map.count(key)){
            int res = map[key]->val;

            Node*& nd = map[key];
            nd->prev->next = nd->next;
            nd->next->prev = nd->prev;

            tail->prev->next = nd;
            nd->prev = tail->prev;
            nd->next = tail;
            tail->prev = nd;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            Node*& nd = map[key];
            nd->prev->next = nd->next;
            nd->next->prev = nd->prev;

            nd->val = value;
            tail->prev->next = nd;
            nd->prev = tail->prev;
            nd->next = tail;
            tail->prev = nd;
        } else {
            if(loglen == size){
                Node* nd = head->next;
                if(nd->next){
                    head->next = nd->next;
                    nd->next->prev = head;
                }
                map.erase(nd->key);
                delete nd;
                loglen--;
            }

            Node* nd = new Node(); nd->val = value; nd->key = key;
            tail->prev->next = nd;
            nd->prev = tail->prev;
            nd->next = tail;
            tail->prev = nd;

            loglen++;
            map[key] = nd;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */