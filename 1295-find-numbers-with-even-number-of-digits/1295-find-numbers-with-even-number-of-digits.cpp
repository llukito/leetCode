class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = 0;
        for(int num : nums){
            string str = to_string(num);
            if(str.size()%2==0){
                n++;
            }
        }
        return n;
    }
};