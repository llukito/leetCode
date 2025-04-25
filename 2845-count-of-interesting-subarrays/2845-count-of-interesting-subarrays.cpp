class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<int> count(nums.size(), 0);
        if(nums[0]%modulo==k){
            count[0]=1;
        } else {
            count[0]=0;
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i]%modulo == k){
                 count[i]=count[i-1] + 1;
            } else {
                count[i]=count[i-1];
            }
        }
        unordered_map<int, int> map;
        map[0]=1;
        long long res=0;
        for(int i=0; i<count.size(); i++){
            int currMod = count[i] % modulo;
            int target = (currMod - k + modulo) % modulo;
            if(map.count(target)){
                res+=map[target];
            }
            map[currMod]++;
        }
        return res;
    }
};