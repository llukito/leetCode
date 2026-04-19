class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;
        for(int i = nums2.size()-1; i >=0; i--){
            sorted.push_back(nums2[i]);
        }

        int res = 0;
        for(int i = 0; i < nums1.size(); i++){
            auto it = lower_bound(sorted.begin(), sorted.end(), nums1[i]);
            if(it == sorted.end())continue;
            int curr = (it-sorted.begin());
            curr = sorted.size()-curr-1;
            res = max(res, curr - i);
        }
        return res;
    }
};
