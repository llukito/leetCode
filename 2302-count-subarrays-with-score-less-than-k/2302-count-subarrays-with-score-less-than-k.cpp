class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long prefixSum[nums.size()+1];
        prefixSum[0] = 0;
        prefixSum[1] = nums[0];
        for(int i=1; i<nums.size(); i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        long long all = 0;
        long long left = 0; long long right = 0;
        while(right<nums.size() && left<nums.size()){
            long long sum = prefixSum[right+1] - prefixSum[left];
            long long size = right-left+1;
            if(left == right){
                sum = nums[right];
            }
            long long res = sum*size;
            if(res<k){
                all+=right-left+1;
                right++;
            } else if(res>=k){
                left++;
            }
        }
        return all;
    }
};