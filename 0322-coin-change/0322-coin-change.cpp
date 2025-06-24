// leetcode number 322 (Coin Change)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        unordered_set<int> st;
        while (!q.empty()) {
            pair<int, int> pr = q.front(); q.pop();
            long long num = pr.first;
            if (num == amount) {
                return pr.second;
            }
            for (int n : coins) {
                if (num + n <= amount && !st.count(num + n)) {
                    st.insert(num + n);
                    q.push({ num + n, pr.second + 1 });
                }
            }
        }
        return -1;
    }
};