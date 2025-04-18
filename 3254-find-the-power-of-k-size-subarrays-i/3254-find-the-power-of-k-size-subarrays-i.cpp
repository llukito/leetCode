class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> vec;
        int left = 0; int right = k-1;
        while(right<nums.size()){
            bool b = true;
            int nn = INT_MIN;
            for(int i=left; i<right; i++){
                nn = max(nn,nums[i]);
                if(nums[i]>=nums[i+1]){
                    b = false;
                    break;
                }
            }
            nn = max(nn, nums[right]);
            if(b){
                vec.push_back(nn);
            } else {
                vec.push_back(-1);
            }
            left++;right++;
        }
        return vec;
    }
};