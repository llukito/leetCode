class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = (int)nums.size();
        vector<long long> ans;
        if (k > n) return ans;

        unordered_map<int,int> cnt;
        // pair: {count, value} ordered ascending; largest are at rbegin()
        set<pair<int,int>> top;   // up to x best elements
        set<pair<int,int>> rest;  // the rest
        long long sumTop = 0;

        auto rebalance = [&](void) {
            // move from rest -> top while top.size() < x
            while ((int)top.size() < x && !rest.empty()) {
                auto it = prev(rest.end());
                auto p = *it;
                rest.erase(it);
                top.insert(p);
                sumTop += 1LL * p.first * p.second;
            }
            // if largest in rest is better than smallest in top, swap them
            while (!rest.empty() && !top.empty() && *prev(rest.end()) > *top.begin()) {
                auto big = *prev(rest.end());
                auto small = *top.begin();
                rest.erase(prev(rest.end()));
                top.erase(top.begin());
                top.insert(big);
                rest.insert(small);
                sumTop += 1LL * big.first * big.second;
                sumTop -= 1LL * small.first * small.second;
            }
            // if top too large (shouldn't normally happen), move smallest to rest
            while ((int)top.size() > x) {
                auto it = top.begin();
                auto p = *it;
                top.erase(it);
                sumTop -= 1LL * p.first * p.second;
                rest.insert(p);
            }
        };

        // Build initial window
        for (int i = 0; i < k; ++i) {
            int v = nums[i];
            int old = cnt[v];
            if (old > 0) {
                // erase old pair from whichever set it is in
                pair<int,int> oldp = {old, v};
                if (top.find(oldp) != top.end()) {
                    top.erase(oldp);
                    sumTop -= 1LL * old * v;
                } else {
                    rest.erase(oldp);
                }
            }
            cnt[v] = old + 1;
            rest.insert({cnt[v], v});
            rebalance();
        }

        ans.push_back(sumTop);

        // Slide window
        for (int i = k; i < n; ++i) {
            int add = nums[i];
            int rem = nums[i - k];

            // remove rem (decrement its count)
            {
                int oldc = cnt[rem];
                pair<int,int> oldp = {oldc, rem};
                if (oldc > 0) {
                    if (top.find(oldp) != top.end()) {
                        top.erase(oldp);
                        sumTop -= 1LL * oldc * rem;
                    } else {
                        rest.erase(oldp);
                    }
                    cnt[rem] = oldc - 1;
                    if (cnt[rem] > 0) {
                        rest.insert({cnt[rem], rem});
                    } else {
                        cnt.erase(rem);
                    }
                }
            }

            // add add (increment its count)
            {
                int oldc = cnt[add];
                if (oldc > 0) {
                    pair<int,int> oldp = {oldc, add};
                    if (top.find(oldp) != top.end()) {
                        top.erase(oldp);
                        sumTop -= 1LL * oldc * add;
                    } else {
                        rest.erase(oldp);
                    }
                }
                cnt[add] = oldc + 1;
                rest.insert({cnt[add], add});
            }

            // rebalance sets so top contains best x
            rebalance();

            ans.push_back(sumTop);
        }

        return ans;
    }
};
