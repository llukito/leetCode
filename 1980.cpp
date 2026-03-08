class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n  = nums.size();
        string curr; for(int i = 0; i < n; i++)curr+='0';
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] != curr){
                return curr;
            }
            add(curr);
        }
        return curr;
    }

    void add(string& curr){
        int left = 1;
        for(int i = curr.size()-1; i>=0; i--){
            if(curr[i] == '0'){
                curr[i] = '1';
                return;
            } else {
                curr[i] = '0';
            }
        }
        curr.insert(0, 1, '0');
    }
};
