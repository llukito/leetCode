// leetcode number 274 (H-Index)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int max_ = citations.size();
        for (int h = max_; h > 0; h--) {
            int index = lower_bound(citations.begin(), citations.end(), h) - citations.begin();
            if (citations.size() - index >= h)return h;
        }
        return 0;
    }
};