class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> map1, map2;
        map<int, int> totalFreq;
        int n = basket1.size();

        int minElement = INT_MAX;
        for (int x : basket1) {
            map1[x]++;
            totalFreq[x]++;
            minElement = min(minElement, x);
        }
        for (int x : basket2) {
            map2[x]++;
            totalFreq[x]++;
            minElement = min(minElement, x);
        }
        for (auto& [key, count] : totalFreq) {
            if (count % 2 != 0) return -1;
        }
        vector<int> extra1, extra2;

        for (auto& [x, count] : totalFreq) {
            int cnt1 = map1[x];
            int cnt2 = map2[x];
            int diff = abs(cnt1 - cnt2) / 2;
            if (cnt1 > cnt2) {
                for (int i = 0; i < diff; ++i)
                    extra1.push_back(x);
            } else if (cnt2 > cnt1) {
                for (int i = 0; i < diff; ++i)
                    extra2.push_back(x);
            }
        }
        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        long long cost = 0;
        for (int i = 0; i < extra1.size(); ++i) {
            int a = extra1[i];
            int b = extra2[i];
            cost += min(min(a, b), 2 * minElement);
        }

        return cost;
    }
};
