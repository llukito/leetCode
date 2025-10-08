class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(), potions.end());
        for(int s : spells){
            int curr = bSearch(potions, success, s);
            res.push_back(curr);
        }
        return res;
    }

    int bSearch(auto& potions, auto& success, auto& s){
        int left = 0; int right = potions.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            long long mult = 1ll*potions[mid]*s;
            if(mult >= success){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return potions.size()-right-1;
    }
};