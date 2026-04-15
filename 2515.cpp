class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int clockwise     = (i - startIndex + n) % n;
                int anticlockwise = (startIndex - i + n) % n;
                res = min(res, min(clockwise, anticlockwise));
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
