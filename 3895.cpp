class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int num = 0;
        for(int n : nums){
            string str = to_string(n);
            for(char ch : str){
                if(ch-'0' == digit){
                    num++;
                }
            }
        }
        return num;
    }
};
