class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> freq(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                if(i == 0){
                    freq[0] = 1;
                    continue;
                }
                freq[i] = freq[i-1]+1;
            } else {
                if(i == 0)continue;
                freq[i] = freq[i-1];
            }
        }
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int last = i-1 >= 0 ? freq[i-1] : 0;
                if(freq[j] - last > (j-i+1)/2){
                    res++;
                }
            }
        }
        return res;
    }
};
