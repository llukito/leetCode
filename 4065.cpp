class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        unordered_set<int> main;
        while(1){
            unordered_set<int> st;
            for(int i = 0; i < nums.size(); i++){
                if(!main.count(i) && !st.count(nums[i])){
                    st.insert(nums[i]);
                    res.push_back(nums[i]);
                    main.insert(i);
                }
            }
            if(st.size() == 0)break;
        }
        return res;
    }
};
