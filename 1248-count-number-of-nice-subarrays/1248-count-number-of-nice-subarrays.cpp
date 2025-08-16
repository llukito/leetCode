class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int curr = 0;
        unordered_map<int,int> map;
        map[0]=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==1){
                curr++;
            }
            if(map.count(curr-k)){
                res+=map[curr-k];
            }
            map[curr]++;
        }
        return res;
    }
};