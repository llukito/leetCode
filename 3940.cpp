class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        if(k == 0)return {};
        vector<int> res;
        int last = -1;
        int occ = -1;
        for(int n : nums){
            if(last == -1){
                last = n;
                occ = 1;
                res.push_back(n);
            } else {
                if(n != last){
                    occ = 0;
                }
                occ++;
                if(occ > k)continue;
                last = n;
                res.push_back(n);
            }
        }
        return res;
    }
};
