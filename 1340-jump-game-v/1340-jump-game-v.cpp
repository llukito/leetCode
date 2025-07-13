class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int m = 0;
        for(int i=0; i<arr.size(); i++){
            vector<int> map(arr.size(), 0);
            int val = check(arr, i, map,d);
            m = max(m,val);
        }
        return m;
    }

   int check(vector<int>& nums,int idx, vector <int>& map, int& d){
        if(map[idx]!=0){
            return map[idx];
        }
        int maxVis = 1;
        for (int i = 1; i <= d; i++) {
            int next = idx + i;
            if (next >= nums.size()) break;
            if (nums[next] >= nums[idx]) break;
            maxVis = max(maxVis, 1 + check(nums, next, map, d));
        }
        for (int i = 1; i <= d; i++) {
            int next = idx - i;
            if (next < 0) break;
            if (nums[next] >= nums[idx]) break;
            maxVis = max(maxVis, 1 + check(nums, next, map, d));
        }
        map[idx] = maxVis;
        return maxVis;
    }
};