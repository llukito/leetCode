class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int m = 0;
        for(int n : nums){
            bitset<8> bits(n);
            if(bits.to_string().back() == '0')m++;
            if(m>1)return 1;
        }
        return 0;
    }
};
