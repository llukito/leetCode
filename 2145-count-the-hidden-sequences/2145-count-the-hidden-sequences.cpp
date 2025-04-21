class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<long long> nums; nums.push_back(0);
        for(int i=0; i<differences.size(); i++){
            long long dif = differences[i];
            dif+=nums.back();
            nums.push_back(dif);
        }
        sort(nums.begin(), nums.end());
        int smallest = nums[0]; int biggest = nums.back();
        long long up = upper-biggest;
        long long lo = lower; lo-=smallest;
        int ans = up-lo+1;
        return ans > 0 ? ans : 0;
    }
};