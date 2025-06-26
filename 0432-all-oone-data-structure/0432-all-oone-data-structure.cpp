class AllOne {
public:
    struct Node{
        unordered_set<string> set;
        int freq;
        Node* next;
        Node* prev;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    unordered_map<string, Node*> map;

    AllOne() {
        head = new Node();
        tail = new Node();
        head->prev = tail->next = nullptr;
        head->next = tail; tail->prev = head;
    }
    
    void inc(string key) {
        if(map.count(key)){
            Node*& nd = map[key];
            nd->set.erase(key);
            Node* temp = nd;
            if(nd->next != tail && nd->next->freq ==nd->freq + 1){
                nd->next->set.insert(key);
                map[key] = nd->next;
            } else {
                Node* addable = new Node(); addable->freq = nd->freq+1;
                addable->set.insert(key);
                addable->prev = nd;
                nd->next->prev = addable;
                addable->next = nd->next;
                nd->next = addable;
                map[key] = addable;
            }
            if(temp->set.size() == 0){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        } else {
            if(head->next != tail && head->next->freq ==1){
                head->next->set.insert(key);
                map[key] = head->next;
            } else {
                Node* addable = new Node(); addable->freq = 1;
                addable->set.insert(key);
                addable->prev = head;
                head->next->prev = addable;
                addable->next = head->next;
                head->next = addable;
                map[key] = addable;
            }
        }
    }
    
    void dec(string key) {
        if(map[key]->freq!=1){
            Node*& nd = map[key];
            nd->set.erase(key);
            Node* temp = nd;
            if(nd->prev != head && nd->prev->freq == nd->freq-1){
                nd->prev->set.insert(key);
                map[key] = nd->prev;
            } else{
                Node* addable = new Node(); addable->freq = nd->freq-1;
                addable->set.insert(key);
                addable->prev = nd->prev;
                nd->prev->next = addable;
                addable->next = nd;
                nd->prev = addable;
                map[key] = addable;
            }
            if(temp->set.size() == 0){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        } else {
             Node*& nd = map[key];
             nd->set.erase(key);
             Node* temp = nd;
             map.erase(key);
             if(temp->set.size() == 0){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }
    
    string getMaxKey() {
        if(tail->prev == head){
            return "";
        }
        for(string s : tail->prev->set){
            return s;
        }
        return "";
    }
    
    string getMinKey() {
        if(head->next == tail){
            return "";
        }
        for(string s : head->next->set){
            return s;
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */