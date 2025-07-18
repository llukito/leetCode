class CustomStack {
public:
    int capacity = 0;
    int loglen = 0;
    vector<int> vect;

    CustomStack(int maxSize) {
        capacity = maxSize;
    }
    
    void push(int x) {
        if(loglen < capacity){
            vect.push_back(x);
            loglen++;
        }
    }
    
    int pop() {
        if(loglen == 0)return -1;
        int val = vect.back();
        vect.pop_back();
        loglen--;
        return val;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<vect.size() && i<k; i++){
            vect[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */