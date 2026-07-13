class DataStream {
public:

    int value = 0, k = 0;
    int cons = 0;

    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if(num == value){
            cons++;
            if(cons >= k){
                return true;
            }
        } else {
            cons = 0;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
