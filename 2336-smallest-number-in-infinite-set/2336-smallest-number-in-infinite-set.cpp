class SmallestInfiniteSet {
public:
    set<int> s;
    int curr = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(s.empty()){
            return curr++;
        }else{
            for(int n : s){
                s.erase(n);
                return n;
            }
        }
        return -1;
    }
    
    void addBack(int num) {
        if(num<curr){
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */