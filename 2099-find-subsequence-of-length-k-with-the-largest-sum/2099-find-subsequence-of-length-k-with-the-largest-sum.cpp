class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> vect(nums.begin(), nums.end());
        sort(vect.begin(), vect.end(), greater<>());
        vector<int> v;
        for(int i=0; i<k; i++){
            v.push_back(vect[i]);
        }
        vector<int> res;
        for(int n : nums){
            auto it = find(v.begin(), v.end(), n);
            if(it!=v.end()){
                res.push_back(n);
                *it = INT_MIN;
            }
            if(res.size() == k)break;
        }
        return res;
    }
};