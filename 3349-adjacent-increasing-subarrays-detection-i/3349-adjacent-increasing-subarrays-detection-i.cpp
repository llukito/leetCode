class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int curr = INT_MIN; int size  = 0; bool b = false;
        vector<int> arr(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if(b && size>=k){
                return true;
            }
            if(nums[i] > curr){
                size++;
            } else {
                if(size>=k)b = true;
                else b = false;
                size = 1;
            }
            curr = nums[i];
            if(size>=2*k)return true;
            arr[i] = size;
        }
        if(b && size>=k){
            return true;
        }
        return false;
    }
};

// 1 2 3 4 5 1 2 3 1 1