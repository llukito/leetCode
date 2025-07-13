class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int,bool> map;
        vector<int> visited(arr.size(), false);
        return check(arr, start, map, visited);
    }

   bool check(vector<int>& nums,int idx, unordered_map<int,bool>& map, vector<int>& visited){
        if(nums[idx] == 0){
            return true;
        }
        if(map.count(idx)){
            return map[idx];
        }
        if(idx+nums[idx] < nums.size() && !visited[idx+nums[idx]]){
            visited[idx+nums[idx]] = true;
            if(check(nums, idx+nums[idx], map, visited)){
                map[idx] = true;
                visited[idx+nums[idx]] = false;
                return true;
            }
            visited[idx+nums[idx]] = false;
        }
        if(idx-nums[idx] >= 0 && !visited[idx-nums[idx]]){
            visited[idx-nums[idx]] = true;
            if(check(nums, idx-nums[idx], map, visited)){
                map[idx] = true;
                visited[idx-nums[idx]] = false;
                return true;
            }
            visited[idx-nums[idx]] = false;
        }
        map[idx] = false;
        return false;
    }
};