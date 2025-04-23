class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> mp;
        int max_ = 0;
        for(int i=1; i<=n; i++){
            string s = to_string(i);
            int sum = 0;
            for(char ch : s){
                sum+=ch-'0';
            }
            mp[sum]++;
            max_ = max(max_, mp[sum]);
        }
        int res = 0;
        for(auto& entry : mp){
            if(entry.second == max_)res++;
        }
        return res;
    }
};