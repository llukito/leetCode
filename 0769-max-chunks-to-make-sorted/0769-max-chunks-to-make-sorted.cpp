class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int maxSeen = 0;
        for (int i = 0; i < arr.size(); ++i) {
            maxSeen = max(maxSeen, arr[i]);
            if (maxSeen == i) {
                res++;
            }
        }
        return res;
    }
};