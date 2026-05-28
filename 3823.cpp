class Solution {
public:
    string reverseByType(string s) {
        vector<char> vect1;
        vector<char> vect2;
        for(char ch : s){
            if(ch >='a' && ch <= 'z'){
                vect1.push_back(ch);
            } else {
                vect2.push_back(ch);
            }
        }
        reverse(vect1.begin(), vect1.end());
        reverse(vect2.begin(), vect2.end());
        string res;
        int idx1, idx2 = 0;
        for(char ch : s){
            if(ch >='a' && ch <= 'z'){
                res+=vect1[idx1++];
            } else {
                res+=vect2[idx2++];
            }
        }
        return res;
    }
};
