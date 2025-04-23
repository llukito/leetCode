class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int n : nums){
            sum+=n;
        }
        int changes = 0;
        while(sum%k!=0){
            sum--;
            changes++;
        }
        return changes;
    }
};