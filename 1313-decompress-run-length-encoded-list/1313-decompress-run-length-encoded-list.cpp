class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size()-1; i+=2){
            int freq = nums[i];
            int num = nums[i+1];
            for(int j=0; j<freq; j++){
                result.push_back(num);
            }
        }
        return result;
    }
};