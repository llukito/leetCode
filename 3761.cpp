class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<string, set<int>> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[to_string(nums[i])].insert(i);
        }
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            string str = to_string(nums[i]);
            string rev = myReverse(str);
            if(mp.count(rev)){
                if(mp[rev].upper_bound(i) == mp[rev].end())continue;
                int r = *(mp[rev].upper_bound(i));
                if(r <= i)continue;
                int curr = r-i;
                if(curr < 0)continue;
                res = min(res, curr);
            }
        }
        return res == INT_MAX ? -1 : res;
    }

    string myReverse(string str){
        reverse(str.begin(), str.end());
        string res;
        bool b = false;
        for(char ch : str){
            if(ch != '0' || b){
                b = true;
                res+=ch;
            } 
        }
        return res;
    }
};
