class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> vec;
        generate(subsets, nums, vec, 0);
        int total = 0;
        for(vector<int> vector : subsets){
            int sum = vector[0];
            cout<<sum<<" ";
            for(int i=1; i<vector.size(); i++){
                cout<<vector[i]<<" ";
                sum^=vector[i];
            }
            cout<<endl;
            total+=sum;
        }
        return total;
    }

    void generate(vector<vector<int>>& subsets, vector<int>& nums, vector<int>& vec, int index){
        if (!vec.empty()){
            subsets.push_back(vec);
        }
        for(int i=index; i<nums.size(); i++){
            vec.push_back(nums[i]);
            generate(subsets, nums, vec, i+1);
            vec.pop_back();
        }
    }
};