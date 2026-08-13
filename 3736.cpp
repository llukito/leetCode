class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int max_ = 0;
        for(int n : nums)max_ = max(n, max_);
        for(int n : nums)moves += abs(max_-n);
        return moves;
    }
};
