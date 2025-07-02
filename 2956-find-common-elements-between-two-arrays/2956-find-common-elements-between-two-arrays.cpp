class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int ans1 = 0;
        for(int n : nums1){
            if(find(nums2.begin(), nums2.end(), n)!=nums2.end()){
                ans1++;
            }
        }
        int ans2 = 0;
        for(int n : nums2){
            if(find(nums1.begin(), nums1.end(), n)!=nums1.end()){
                ans2++;
            }
        }
        res.push_back(ans1); res.push_back(ans2);
        return res;
    }
};