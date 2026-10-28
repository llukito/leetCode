class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set;
        for(int n : nums){
            if(n%k==0){
                set.insert(n/k);
            }    
        }
        for(int i = 1; ; i++){
            if(!set.count(i)){
                return k*i;
            }
        }
        return -1;
    }
};
