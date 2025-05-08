class Solution {
public:
    bool checkPerfectNumber(int num) {
        // pre computed perfect numbers up to 10^8 which is the constraint
        unordered_set<int> set = {6, 28, 496, 8128, 33550336};
        return set.count(num);
    }
};