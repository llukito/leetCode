class Solution {
public:
    string stringHash(string s, int k) {
        string res;
        int sum = 0;
        int idx = 0;
        for(int i=0; i<s.length(); i++){
            sum+=(s[i]-'a');
            idx++;
            if(idx == k){
                sum%=26;
                char ch = static_cast<char>('a'+sum);
                res+=ch;
                sum = 0;
                idx = 0;
            }
        }
        return res;
    }
};