class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = 0;
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[((i%value)+value)%value]++;
        }
        int m = 0;
        while(m < nums.size()){
            int val = m%value;
            if(!mp.count(val) || mp[val] <= 0)break;
            mp[val]--;
            m++;
        }
        return m;
    }
};