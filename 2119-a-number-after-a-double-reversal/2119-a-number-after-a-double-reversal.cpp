class Solution {
public:
    bool isSameAfterReversals(int num) {
        string str = to_string(num);
        reverse(str.begin(), str.end());
        int n = stoi(str);
        str = to_string(n);
        reverse(str.begin(), str.end());
        return stoi(str) == num;
    }
};