class Solution {
public:
    bool checkPerfectNumber(int num) {
        unordered_set<int> set = {6, 28, 496, 8128, 33550336};
        return set.count(num);
    }
};