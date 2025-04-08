class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minNum = 0;
        while(!isDistinct(nums)){
            int size = nums.size();
            if(size<=3){
                minNum++;
                return minNum;
            }
            for(int i=0; i<3; i++){
                nums.erase(nums.begin());
            }
            minNum++;
        }
        return minNum;
    }

    bool isDistinct(vector<int>& nums){
        unordered_set<int> set;
        for(int n : nums){
            if(set.count(n)){
                return false;
            }
            set.insert(n);
        }
        return true;
    }
};