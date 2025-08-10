class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> m;
        for(int n : nums){
            m[n]++;
        }
        int leftOver = 0; int pairs = 0;
        for(auto& entry : m){
            int n = entry.second;
            if(entry.second%2==1){
                leftOver++;
                n--;
            }
            pairs += n/2;
        }
        return {pairs, leftOver};
    }
};