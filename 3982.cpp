class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int max_ = 0;
        vector<int> v;
        for(int n : nums){
            v.push_back(digitsRange(n));
            max_ = max(max_, v.back());
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(v[i] == max_){
                sum+=nums[i];
            }
        }
        return sum;
    }

    int digitsRange(int n){
        int max_ = INT_MIN;
        int min_ = INT_MAX;
        while(n){
            int rem = n%10;
            max_ = max(max_, rem);
            min_ = min(min_, rem);
            n/=10;
        }
        return max_ - min_;
    }
};
