class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> changes;
        for(int bill : bills){
            vector<int> vec;
            if(!canMake(changes,bill-5,0,vec))return false;
            changes.push_back(bill);
        }
        return true;
    }

    bool canMake(vector<int>& changes, int bill, int index, vector<int>& vec){
        if(bill==0){
            for (int val : vec) {
                auto it = find(changes.begin(), changes.end(), val);
                if (it != changes.end()) {
                    changes.erase(it); 
                }
            }
            return true;
        }
        if(bill<0){
            return false;
        }
        for(int i=index; i<changes.size(); i++){
            vec.push_back(changes[i]);
            if(canMake(changes, bill-changes[i], i+1, vec)){
                return true;
            }
            vec.pop_back();
        }
        return false;
    }
};