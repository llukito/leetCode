class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> vv;
        for(int i=0; i<=nums.size()-k; i++){
            map<int,int> m;
            for(int j=i; j<i+k; j++){
                int n = nums[j];
                m[n]++;
            }
            vector<pair<int,int>> v;
            for(auto& entry : m){
                v.push_back({entry.second, entry.first});
            }
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            int res = 0;
            for(int j = 0; j<v.size() && j<x; j++){
                res+=v[j].first*v[j].second;
            }
            vv.push_back(res);
        }
        return vv;
    }
};