class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string next_s = "";

            for (int i = 0; i < s.size(); i += k) {
                int sum = 0;
                
                for (int j = i; j < i + k && j < s.size(); j++) {
                    sum += s[j] - '0';
                }
                next_s += to_string(sum);
            }
            s = next_s;
        }
        
        return s;
    }
};
