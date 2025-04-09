class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(invalid(nums, k))return -1;
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> vector(set.begin(), set.end());
        sort(vector.begin(), vector.end());
        int count = 0;
        if(vector.size()==1){
            if(vector[0]==k){
                return 0;
            } 
        }
        while(true){
            if(vector.size()==1)return count+1;
            int largest = vector.back(); vector.pop_back();
            int second = vector.back();
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==largest){
                    nums[i] == second;
                }
            }
            count++;
            if(second==k)return count;
        }
    }

    bool invalid(vector<int>& nums, int& k){
        for(int n : nums){
            if(n<k){
                return true;
            }
        }
        return false;
    }
};