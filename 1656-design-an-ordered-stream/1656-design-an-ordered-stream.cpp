class OrderedStream {
public:
    string* arr;
    int ptr;
    int size;
    OrderedStream(int n) {
        arr = new string[n];
        ptr = 0;
        size = n;
    }
    
    vector<string> insert(int idKey, string value) {
        idKey--;
        arr[idKey] = value;
        vector<string> res;
        if(ptr == idKey){
            int neww = ptr+1;
            for(int i=ptr; i<size; i++){
                if(arr[i].empty())break;
                res.push_back(arr[i]);
                neww = i+1;
            }
            ptr = neww;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */