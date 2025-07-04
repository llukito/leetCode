class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> lengths(n + 1);
        lengths[0] = 1;

        for (int i = 0; i < n; ++i) {
            lengths[i+1] = lengths[i] * 2;
            if (lengths[i+1] >= k) break;
        }

        int shifts = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (k <= lengths[i]) {
            } else {
                k -= lengths[i];
                if (operations[i] == 1)
                    shifts++;  
            }
        }

        return 'a' + (shifts % 26);
    }
};