class Solution {
public:
    int maxLength(vector<int>& nums) {
        int best = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long prod = 1, g = 0, l = 1;
            for (int j = i; j < nums.size(); j++) {
                prod *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if(prod == l*g) best = max(best, j - i + 1);
                if(prod > l*g)break;
            }
        }
        return best;
    }
};
